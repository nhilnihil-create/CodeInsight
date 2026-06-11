#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define dcout cout << fixed << setprecision(15)
#define arep(i, a) for(auto i : a)
#define F first
#define S second
#define VE vector<int>
#define pb(x) push_back(x)
#define MOD 1000000007
#define INF 10000000000
#define int long long
#define KETA(n) floor(log10(n) + 1)
using namespace std;
signed main() {
    string s;
    cin >> s;
    int ans = 700;
    if(s[0] == 'o') ans += 100;
    if(s[1] == 'o') ans += 100;
    if(s[2] == 'o') ans += 100;
    cout << ans << endl;
    return 0;
}