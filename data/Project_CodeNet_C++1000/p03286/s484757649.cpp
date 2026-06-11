#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;
    if (N == 0) {
        cout << "0" << endl;
        return 0;
    }

    ll base = 1;

    string ans = "";
    while (N != 0) {
        // cout << "base " << base << endl;
        // int modc = abs(N % (base * 2));
        // cout << modc << endl;
        if (abs(N % (base*2)) == base) {
            ans += '1';
            N -= base * pow(-1, int(ans.size()+1));
            // cout << "new N " << N << endl;
        } else {
            ans += '0';
        }
        base *= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
/*

123456789
11000101011001101110100010101
11000101011001101110100010101
*/
