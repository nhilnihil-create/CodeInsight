#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <map>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 100000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m, k, i, j;
    string s;
    cin >> n >> s;;

    int tmp;
    vector<int> ans(n,0), west(n,0), east(n,0);
    for(i = 1; i < n; i++) {
        if (s[i-1] == 'W') {
            west[i] = west[i-1] + 1;
        } else {
            west[i] = west[i-1];
        }
    }

    for(i = n - 1 - 1; i >= 0; i--) {
        if(s[i+1] == 'E') {
            east[i] = east[i+1] + 1;
        } else {
            east[i] = east[i+1];
        }
    }

    rep(i,n) {
        ans[i] = west[i] + east[i];
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}
