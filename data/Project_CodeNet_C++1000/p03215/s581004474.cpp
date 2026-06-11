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
    int n,k;
    cin >> n >> k;
    ll a[n];
    REP(i,n){
        cin >> a[i];
    }
    vector<ll> vec;
    REP(i,n){
        ll sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            vec.push_back(sum);
        }
    }
    ll ans = 0;
    for(int i = 40; i >= 0; i--){
        ll mask = 1LL << i;
        int cnt = 0;
        vector<ll> use;
        REP(j,vec.size()){
            if(vec[j] & mask){
                cnt++;
                use.emplace_back(vec[j]);
            }
        }
        if(cnt >= k){
            ans += mask;
            vec = use;
        }
    }
    cout << ans << endl;
    return 0;
}