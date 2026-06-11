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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> v1(26, -1);
    vector<int> v2(26, -1);
    int n = s.size();
    rep(i, n) {
        if (v1[s[i]-'a'] == -1) {
            v1[s[i]-'a'] = t[i]-'a';
        }
        else if (v1[s[i]-'a'] != t[i]-'a'){
            cout << "No" << endl;
            return 0;
        }
        if (v2[t[i]-'a'] == -1) {
            v2[t[i]-'a'] = s[i]-'a';
        }
        else if (v2[t[i]-'a'] != s[i]-'a') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
