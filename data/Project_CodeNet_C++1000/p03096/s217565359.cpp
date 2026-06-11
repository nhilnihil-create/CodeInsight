#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1e9+7;
vector<int> v;
vector<int> jump;
int memo[200010],pos[200010];
int dp(int n){
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    if (jump[n] != -1) return memo[n] = (dp(n-1)+dp(jump[n]))%MOD;
    return memo[n] = dp(n-1)%MOD;
}
main(){
    int n;
    cin >> n;
    int prev = -1;
    for (int i = 0; i < 200010; i++) memo[i] = pos[i] = -1;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        if (c == prev) continue;
        prev = c;
        v.push_back(c);
        jump.push_back(pos[c]);
        pos[c] = v.size()-1;
    }
  //  for (int i = 0; i < v.size(); i++) cout << dp(i);
    cout << dp(v.size()-1);
    //for (int i = 0; i < v.size(); i++) cout << v[i] << jump[i] << "\n";
}
