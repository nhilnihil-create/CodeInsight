#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

const ll mod=1e9+7;
const ll inf=1ll<<60;

/*---------------------*/

ll t,a,b,c,d;

int main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(a<b||d<b){
            cout<<"No\n";
            continue;
        }if(c>=b){
            cout<<"Yes\n";
            continue;
        }
        ll g=__gcd(b,d);
        if(b+a%g-g>c)cout<<"No\n";
        else cout<<"Yes\n";
    }
}