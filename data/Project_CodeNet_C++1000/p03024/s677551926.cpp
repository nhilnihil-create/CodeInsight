#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
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

    int cnt = 0;
    rep(i, s.size()) {
        if(s[i] == 'x') {
            cnt++;
        }
    }

    if(cnt < 8) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    cout << endl;
    return 0;
}