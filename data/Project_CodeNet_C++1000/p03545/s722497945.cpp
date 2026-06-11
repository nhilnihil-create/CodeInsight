#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    cin >> s;
    vector<int> a(4);
    rep(i, 4) a[i] = s[i] - '0';
    rep(S, 1 << 3) {
        int ans = a[0];
        rep(i, 3) {
            if(S>>i & 1) ans += a[i + 1];
            else ans -= a[i + 1];
        }
        if(ans == 7) {
            string s = "0-0-0-0=7";
            rep(i, 4) s[i*2] = '0' + a[i];
            rep(i, 3) if(S>>i & 1) s[i*2+1] = '+';
            cout << s << endl;
            return 0;
        }
    }

    return 0;
}