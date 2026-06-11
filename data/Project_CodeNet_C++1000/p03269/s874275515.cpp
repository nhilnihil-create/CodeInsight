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

int main(){
    int l,n,m=1; cin>>l;
    l--;
    if(l==1){
        cout<<2<<" "<<2<<endl;
        cout<<1<<" "<<2<<" "<<0<<endl;
        cout<<1<<" "<<2<<" "<<1<<endl;
    }
    else{
    rep(i,21){
        if(m>l){
            n=i; m=2*n-1; break;
        }
        m<<=1;
    }
    for(int i=1;i<n-1;i++)if((1<<i)&l) m++;
    cout<<n<<" "<<(l!=3 ? m : m+1)<<endl;
    rep(i,n-1){
        cout<<i+1<<" "<<i+2<<" "<<0<<endl;
        cout<<i+1<<" "<<i+2<<" "<<(1<<(n-2-i))<<endl;
    }
    int c=(1<<(n-1));
    for(int i=1;i<n-1;i++){
        if((1<<(n-1-i))&l){
            cout<<1<<" "<<i+1<<" "<<c<<endl;
            c+=(1<<(n-1-i));
        }
    }
    if(l==3){
        cout<<1<<" "<<2<<" "<<2<<endl;
        cout<<1<<" "<<2<<" "<<3<<endl;
    }
    else if(1&l){
        cout<<1<<" "<<n-1<<" "<<c<<endl;
    }
    else{
        cout<<1<<" "<<n<<" "<<c<<endl;
    }
    }
}