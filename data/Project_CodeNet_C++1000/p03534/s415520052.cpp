#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <regex>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

int cnt[3];

int main() {
    string s;
    cin >> s;
    REP(i,s.size()) {
        cnt[s[i] - 'a']++;
    }
    
    sort(cnt, cnt+3);
    if (cnt[2] - cnt[0] <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
