#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    if (s == "keyence") {
        cout << "YES" << endl;
        return 0;
    }
    rep(i, (int)s.size()) {
        for (int j = i; j < (int)s.size(); ++j) {
            string t = "";
            rep(k, s.size()) {
                if (k >= i && k <= j) continue;
                t += s[k];
            }
            //cout << t << endl;
            if (t == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
