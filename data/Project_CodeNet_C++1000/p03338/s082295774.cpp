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
#define TEN5 100000 //10^5
#define TEN9 1000000000 //10^9
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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep1(i,n) {
        string sf = s.substr(0,i);
        string sb = s.substr(i+0,n);
        int sfi = 0, sbi = 0;
        rep(j,sf.length()) {
            int shift = 1;
            shift = shift << (int)(sf[j] - 'a');
            sfi |= shift;
        }
        rep(j,sb.length()) {
            int shift = 1;
            shift = shift << (int)(sb[j] - 'a');
            sbi |= shift;
        }
        bitset<26> f(sfi), b(sbi);
        //cout << f << " " << b << endl;
        f &= b;
        int cnt = 0;
        rep(j,26) {
            bitset<26> base(1);
            base &= f;
            if (base == 1)
                cnt++;
            f >>= 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

