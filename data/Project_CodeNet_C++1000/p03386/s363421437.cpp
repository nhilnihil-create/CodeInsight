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

#define rep(i,n) for (int i = 0; i < (n); i++)
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

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    set<int> s;
    for(int i = a; i < a + k && i <= b; i++)
        s.insert(i);
    for(int i = b; i > b - k && i >= a; i--)
        s.insert(i);

    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    return 0;
}
