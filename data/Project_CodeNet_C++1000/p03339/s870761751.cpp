#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n), e(n);
    for (int i = 1; i < n; i++)
    {
        w[i] = w[i-1];
        if (s[i-1] == 'W') w[i]++;
    }
    for (int i = n-2; i >= 0; i--)
    {
        e[i] = e[i+1];
        if (s[i+1] == 'E') e[i]++;
    }
    int ans = INT_MAX;
    rep(i,n) {
        ans = min(ans, w[i]+e[i]);
    }
    cout << ans << endl;
    return 0;
}