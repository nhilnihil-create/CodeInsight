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

vector<int> v;

void init_uf(int n){
    v.assign(n,-1);
}

int find_(int x){
    if(v[x]<0) return x;
    v[x]=find_(v[x]);
    return v[x];
}

int same_(int a,int b){
    if(find_(a)==find_(b)) return 1;
    return 0;
}

void union_(int a,int b){
    if(same_(a,b)) return;
    int a_p=find_(a),b_p=find_(b);
    if(a_p>b_p) swap(a_p,b_p);
    v[a_p]+=v[b_p]; v[b_p]=a_p;
}

void print_v(){
    rep(i,v.size()) cout<<v[i]<<" ";
    cout<<endl;
}

int size_(int a){
    return -v[find_(a)];
}

int main(){
    int n,m; cin>>n>>m;
    init_uf(n);
    rep(i,m){
        int x,y,z; cin>>x>>y>>z;
        x--; y--;
        union_(x,y);
    }
    int ans=0;
    rep(i,n) if(v[i]<0) ans++;
    cout<<ans<<endl;
}