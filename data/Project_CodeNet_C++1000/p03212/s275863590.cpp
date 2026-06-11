#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

ll N;
ll sft[3] = {3, 5, 7};
ll ans = 0;

void dfs(ll sum, map<ll, ll> m){
    if(sum <= N){
        if(m[3] && m[5] && m[7]) ans++;

        for(auto n : sft){
            map<ll, ll> m2 = m;
            m2[n]++;
            dfs(sum * 10 + n, m2);
        }
    }
}

int main() {
    cin >> N;
    map<ll, ll> m;
    dfs(0, m);
    cout << ans << endl;

}
