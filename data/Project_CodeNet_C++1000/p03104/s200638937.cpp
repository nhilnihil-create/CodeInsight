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

int main() {
    ll a,b,ans=0; cin>>a>>b;
    if(a>0) a--;
    if(b&(1LL)){
        if(!(b&(1LL<<1))) ans^=1LL;
    }
    else{
        if(b&(1LL<<1)) ans^=1;
        rep(i,50){
            if(b&(1LL<<(i+1))) ans^=(1LL<<(i+1));
        }
    }
    if(a&(1LL)){
        if(!(a&(1LL<<1))) ans^=1LL;
    }
    else{
        if(a&(1LL<<1)) ans^=1;
        rep(i,50){
            if(a&(1LL<<(i+1))) ans^=(1LL<<(i+1));
        }
    }
    cout<<ans<<endl;
}