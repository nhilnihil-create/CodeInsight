#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;

int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0; 
    for(ll i=1;i*i<=m;i++){
        //cout<<i<<endl;
        if(m%i==0){
            //cout<< "Yes" << endl;
            ll now1 = i, now2 = m/i;
            if(now1*n<=m) ans = max(ans,now1);
            if(now2*n<=m) ans = max(ans,now2);
        }
    }
    cout << ans << endl;
    return 0;
}