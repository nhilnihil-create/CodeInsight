#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

string s;
int memo[310][310][310];

int calc(int l, int r, int k){
    if(k < 0) return -INF;
    if(l > r) return 0;
    if(memo[l][r][k]) return memo[l][r][k];
    if(l == r) return memo[l][r][k] = 1;
    int res = 0;
    if(s[l] == s[r]) res = max(res, calc(l + 1, r - 1, k) + 2);
    else res = max({res, calc(l + 1, r, k), calc(l, r - 1, k), calc(l + 1, r - 1, k - 1) + 2});
    return memo[l][r][k] = res;
}

int main(){
    int k;
    cin >> s >> k;
    cout << calc(0, s.size() - 1, k) << endl;    
}