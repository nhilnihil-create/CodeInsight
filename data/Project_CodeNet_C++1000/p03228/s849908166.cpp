#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, k;
    cin >> a >> b >> k;
    rep(i, k) {
        if (i % 2 == 0) {
            b = b + a / 2;
            a = a / 2;
        }
        else {
            a = a + b / 2;
            b = b / 2;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
