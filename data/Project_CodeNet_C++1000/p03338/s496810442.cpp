#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
typedef long long ll;
const int START_N = 97;
const int END_N = 122;

int main() {
    int n;
    cin >> n;

    string text;
    cin >> text;

    char c = START_N;
    bool a[26];
    bool b[26];
    int max = 0;

    rep(i, n - 1) {
        fill_n(a, 26, false);
        fill_n(b, 26, false);
        
        int res = 0;
        rep(j, n) {
            int num = text.at(j);
            num = num - START_N;

            if (j <= i) {
                a[num] = true;
            } else {
                if (a[num] == true && b[num] == false) {
                    res++;
                    b[num] = true;
                }
            }
        }

        if (res > max) {
            max = res;
        }
    }

    cout << max << endl;
}