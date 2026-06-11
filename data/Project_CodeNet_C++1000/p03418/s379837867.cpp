#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < (n); i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, k, n) for (int i = (k); i < (n); i++)
#define REPEACH(itr, k) for (auto &&itr : k)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;


const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main()
{
    int n,k;
    cin >> n >> k;
    ll ans=0;
    ll j=0;
    for(int i=k+1;i<=n;i++){
        ans+=(n/i)*(i-k);
        int tmp=n%i;
        ans+=max(0,tmp-k+1);
        if(k==0){
            ans--;
        }
    }
    cout << ans << endl;
}