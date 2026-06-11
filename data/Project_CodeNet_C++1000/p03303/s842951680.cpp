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
    int w;
    cin >> s >> w;

    rep(i, s.size()) {
        if(i%w == 0) {
            cout << s[i];
        }
    }

    cout << endl;
    return 0;
}