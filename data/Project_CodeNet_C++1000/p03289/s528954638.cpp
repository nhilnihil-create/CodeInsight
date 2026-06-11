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
    string s;
    cin >> s;
    
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    int flag = 0;
    for(int i = 2; i < s.length() - 1; i++) {
        if(s[i] == 'C')
            flag++;
    }
    if (flag != 1) {
        cout << "WA" << endl;
        return 0;
    }

    rep(i,s.length()) {
        if (i == 0 || s[i] == 'C')
            continue;
        if (s[i] < 'a' || s[i] > 'z') {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;

    return 0;
}
