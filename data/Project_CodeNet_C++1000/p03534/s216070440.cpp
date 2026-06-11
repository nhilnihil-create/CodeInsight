#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;

    int cnta = 0, cntb = 0, cntc = 0;
    rep(i, s.size()) {
        if(s[i] == 'a') {
            cnta++;
        }
        else if(s[i] == 'b') {
            cntb++;
        }
        else {
            cntc++;
        }
    }

    int x[3] = {cnta, cntb, cntc};
    sort(x, x+3);

    int t = x[2] - x[0];
    if(t <= 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    cout << endl;
    return 0;
}