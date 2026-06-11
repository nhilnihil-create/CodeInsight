#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

const int a = 'z'-'a'+1;

int opt(int h, const vector<int> &dp){
    int res = dp[h];
    REP(i, a){
        res = min(res, dp[h^(1<<i)]);
    }
    return res;
}

int main(){
    string S;
    cin >> S;
    int n = S.size();
    vector<int> dp(1<<a, n);
    dp[0] = 0;
    int hash = 0;
    REP(i, n){
        hash ^= 1<<(S[i]-'a');
        int tmp = opt(hash, dp);
        dp[hash] = min(dp[hash], tmp+1);
    }
    cout << opt(hash, dp)+1 << endl;
    return 0;
}
