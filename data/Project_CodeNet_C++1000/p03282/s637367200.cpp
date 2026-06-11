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

#define rep(i,n) for (long long int i = 0; i < (n); i++)
#define rep1(i,n) for (long long int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

char a[1000][1000];
int main()
{
    string s; cin >> s;
    ll k;cin >> k;

    int flag = 1;
    int i;
    for(i = 0; i < min((ll)s.length(), k); i++) {
        if (s[i] != '1') {
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}
