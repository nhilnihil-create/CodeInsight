#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

double expectation(int p);

int main() {
    string s, t;
    bool ans = false;
    cin >> s >> t;

    int x = s.size(), y = t.size();

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<>());


    for (int i = 0; i < min(x, y); i++) {
        if(s[i] < t[i]){
            ans = true;
            goto Ans;
        }
        else if (s[i] == t[i]) {
            continue;
        }
        else {
            ans = false;
            goto Ans;
        }
    }

    if (x > y) {
        ans = false;
    }
    else if(x < y) {
        ans = true;
    }


Ans:
    if (ans) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}
