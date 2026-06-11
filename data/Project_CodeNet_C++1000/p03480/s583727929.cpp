#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

const int MAX_N = 100100;
int N;
int dir[MAX_N];
int f[MAX_N]; //[i, i+K-1]を反転させたかどうか

bool calc(int K){
    memset(f, 0, sizeof(f));
    int res = 0;
    int sum = 0;
    for (int i = 0; i + K - 1 <= N - 1; i++) {
        if ((dir[i] + sum) % 2 != 0) {
            res++;
            f[i] = 1;
        } 
        sum += f[i];
        if (i - K + 1 >= 0) {
            sum -= f[i - K + 1];
        } 
    }

    int i = N - K + 1;
    bool flag = true;
    while (i < K) {
        if ((dir[i] + sum)%2 != 0) {
            flag = false;
        } 
        i++;
    }
    return flag;
}

int main () {
    
    string s; cin >> s;
    N = s.length();
    for (int i = 0; i < N; i++) {
        if (s[i] == '0') {
            dir[i] = 0;
        } else {
            dir[i] = 1;
        } 
    }

    vector<int> v(N);
    REP(i, N) v[i] = i+1;
    int ok = -1;
    int ng = v.size();
    while (abs(ok - ng) > 1) {
        int m = (ok+ng)/2;
        if (calc(v[m])) {
            ok = m;
        } else {
            ng = m;
        } 

    }
    cout << v[ok] << endl;
    
    return 0;
}





