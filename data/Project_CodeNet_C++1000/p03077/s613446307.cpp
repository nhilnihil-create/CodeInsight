#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll n,a,b,c,d,e;
    cin>>n>>a>>b>>c>>d>>e;
    ll mi=min({a,b,c,d,e});
    ll ans=(n+mi-1)/mi+4;

    cout<<ans<<endl;
}