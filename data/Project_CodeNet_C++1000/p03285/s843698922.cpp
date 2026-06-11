#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string ans = "No";
    for(int i = 0; 4 * i <= n; i++) {
        for(int j = 0; 7 * j <= n; j++) {
            if(4 * i + 7 * j == n) {
                ans = "Yes";
                break;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}
