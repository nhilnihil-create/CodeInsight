#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> cnt(26, 0);
    rep(i, n){
        cnt[s[i] - 'a']++;
    }

    ll ans = 1;
    for (auto& p : cnt) {
        ans *= p+1;
        ans %= MOD;
    }
    ans--;
    ans %= MOD;
    cout << ans << endl;

    return 0;
}
