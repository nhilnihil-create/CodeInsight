//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int n,N;
vector<int> v;

void init(){
    N=1;
    while(N<n) N*=2;
    v.assign(2*N-1,0); //変更点
}

void init_u(){
    for(int i=N-2;i>=0;i--)
    v[i]=v[2*i+1]+v[2*i+2]; //変更点
}

void update(int k,int a){
    k+=N-1;
    v[k]=a;
    while(k>0){
        k=(k-1)/2;
        v[k]=v[k*2+1]+v[k*2+2]; //変更点
    }
}

//query(a,b,0,0,N);
int query(int a,int b,int k,int l,int r){
    if(r<=a || b<=l) return 0; //変更点
    if(a<=l && r<=b) return v[k];
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return vl+vr; //変更点
}

int main(){
    cin>>n;
    int q; cin>>q;
    string s; cin>>s;
    init();
    rep(i,n-1){
        if(s[i]=='A' && s[i+1]=='C') v[i+N-1]=1;
    }
    init_u();
    rep(i,q){
        int l,r; cin>>l>>r;
        printf("%d\n",query(l-1,r-1,0,0,N));
    }
}