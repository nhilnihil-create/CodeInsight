#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long         ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main() {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int N = s.size();

    vector<int> d;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'T') {
            d.push_back(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    d.push_back(cnt);

    int D = d.size();
    vector<unordered_set<int>> dp(D);
    dp[0].insert(d[0]);

    int xmax = ((D - 1) / 2) * 2;
    int ymax = (D / 2) * 2 - 1;

    for (int i = 2; i < D; i+=2) {
        for(auto &s : dp[i - 2]) {
            dp[i].insert(s + d[i]);
            dp[i].insert(s - d[i]);
        }
    }

    for (int i = 1; i < D; i+=2) {
        if (i == 1) {
            dp[i].insert(d[i]);
            dp[i].insert(-d[i]);
        } else {
            for(auto &s : dp[i - 2]) {
                dp[i].insert(s + d[i]);
                dp[i].insert(s - d[i]);
            }
        }
    }
    bool xok = false, yok = false;
    if (ymax == -1) {
        yok = y == 0;
    } else {
        yok = dp[ymax].find(y) != dp[ymax].end();
    }
    xok = dp[xmax].find(x) != dp[xmax].end();

    if (yok && xok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
