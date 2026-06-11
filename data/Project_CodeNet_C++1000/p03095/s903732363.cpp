#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)
#define MOD 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1;
    vector<int> count(26, 0);
    
    for(int i = 0; i < n; i++) {
        count[s[i]-'a']++;
    }

    rep(i, 0, count.size()) {
        if(count[i] == 0) {
            continue;
        }
        ans *= count[i]+1;
        ans %= MOD;
    }
    cout << ans-1 << endl;
}