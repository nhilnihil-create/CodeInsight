#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll a[n];
    map<ll, int> mp;
    REP(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(mp[a[i]] <= 0) continue;
        mp[a[i]]--;
        for(ll j = 40; j > 0; j--){
            if(pow(2LL, j) - a[i] <= 0) break;
            if(mp.count(pow(2LL, j) - a[i]) && mp[pow(2LL, j) - a[i]] > 0){
                ans++;
                mp[pow(2LL, j) - a[i]]--;
                goto find;
            }
        }
        find:;
    }
    cout << ans << endl;
    return 0;
}