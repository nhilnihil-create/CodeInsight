#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    REP(i, n - 1) {
        if(s[i] != s[i + 1]) {
            int dist = max(i + 1, n - i - 1);
            ans = min(ans, dist);
        }
    }
    cout << ans << endl;
    return 0;
}
