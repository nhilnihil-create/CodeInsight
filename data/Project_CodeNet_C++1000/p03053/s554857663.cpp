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
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int INF = numeric_limits<int>::max();

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

int main()
{
    int h, w;
    cin >> h >> w;
    char s[h][w];
    int sharp = 0;
    queue<PII> q;
    rep(i,h){
        rep(j,w) {
            char tmp;
            cin >> tmp;
            s[i][j] = tmp;
            if (tmp == '#') {
                q.emplace(i, j);
                sharp++;
            }
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int preve = 0;
    int ans = 0;
    while(sharp < h * w) {
        int tmp = sharp - preve;
        preve = sharp;
        rep(j,tmp) {
            PII now = q.front();
            q.pop();
            rep(i,4) {
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w
                        || s[nx][ny] == '#')
                    continue;
                s[nx][ny] = '#';
                q.emplace(nx, ny);
                sharp++;
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
