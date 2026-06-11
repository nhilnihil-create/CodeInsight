//Feet don't fail me now
//Take me to the finish line
//Oh, my heart, it breaks every step that I take
//But I'm hoping at the gates, they'll tell me
//that IOI gold is mine
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define no_answer {cout << "NO"; exit(0);}
#define vectors vector<vector<llong> >
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)

const long long MXN = 2e5 + 10;
const long long MNN = 1e4 + 520;
const long long MOD = 10007;
const long long INF = 1e18;
const long long OO = 1e9;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int h, w, n, dp[MXN][4];
int curx, cury;
string s, t;

bool check(int pos){
    if(dp[pos][0] <= 0){
        return true;
    }
    if(dp[pos][1] > w){
        return true;
    }
    if(dp[pos][2] <= 0){
        return true;
    }
    if(dp[pos][3] > h){
        return true;
    }
    return false;
}

int main(){
    ios;
    cin >> h >> w >> n;
    cin >> curx >> cury;
    cin >> s >> t;
    s = '#' + s;
    t = '#' + t;
    dp[0][0] = dp[0][1] = cury;
    dp[0][2] = dp[0][3] = curx;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++) dp[i][j] = dp[i - 1][j];
        
        if(s[i] == 'L') dp[i][0] = dp[i - 1][0] - 1;
        if(s[i] == 'R') dp[i][1] = dp[i - 1][1] + 1;
        if(s[i] == 'U') dp[i][2] = dp[i - 1][2] - 1;
        if(s[i] == 'D') dp[i][3] = dp[i - 1][3] + 1;
        
        if(check(i)) return cout << "NO", 0;
        
        if(t[i] == 'L') dp[i][1] = max(dp[i][1] - 1, 1);
        if(t[i] == 'R') dp[i][0] = min(dp[i][0] + 1, w);
        if(t[i] == 'U') dp[i][3] = max(dp[i][3] - 1, 1);
        if(t[i] == 'D') dp[i][2] = min(dp[i][2] + 1, h);
    }
    cout << "YES";
}
