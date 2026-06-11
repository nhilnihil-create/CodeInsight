#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};

//ll mod = 1000000009;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int n, cnt = 0, a = 0, b = 0,ab = 0; cin >> n;
    rep(i,n){
        string s; cin >> s;
        int l = s.size();
        rep(j,l-1){
            if(s[j]=='A'&&s[j+1]=='B') cnt++;
        }
        if(s[0] == 'B' && s[l-1] == 'A') ab++;
        else if(s[0] == 'B') b++;
        else if(s[l-1] == 'A') a++;
    }
    int ans = 0;
    if(ab > 0) {
        if (a > 0 && b > 0) ans = ab - 1 + 2 + min(a - 1, b - 1);
        else if (a > 0 && b == 0) ans = ab;
        else if (a == 0 && b > 0) ans = ab;
        else ans = ab - 1;
    }else{
        ans = min(a,b);
    }
    cout << ans + cnt << endl;
}


