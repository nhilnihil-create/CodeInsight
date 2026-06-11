#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int b = 0, w = 0;

    vi black(n, 0), white(n, 0);

    rep(i, n) {
        if (s[i] == '#') {
            b++;
        } else {
            white[i] = b;
            w++;
        }
    }
    //all b or all w
    int num = min(b, w);

    b = 0;
    w = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '#') {
            b++;
            black[i] = w;
        } else {
            w++;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            int t = 0;

            t += white[i];

            while (s[i] != '#') {
                i++;

                if(i==s.size()){
                    break;
                }
            }

            t += black[i];

            num = min(num, t);

            i++;
        }
    }

    cout << num << endl;
}