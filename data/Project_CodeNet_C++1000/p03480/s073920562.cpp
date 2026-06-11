#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    int ans = n;
    char c = s[0];
    rep(i, n){
        if(c != s[i]){
            c = s[i];
            int l = max(i, n-i);
            ans = min(ans, l);
        }
    }
    cout << ans << endl;
}