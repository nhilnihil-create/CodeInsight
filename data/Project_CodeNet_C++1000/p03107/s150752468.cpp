#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
ll mod = 1e9+7;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt=0;
    int ans;
    rep(i,n){
        if(s[i] == '0') cnt++;
    }
    ans = 2 * min(cnt, n-cnt);
    cout << ans << endl;

    return 0;
}