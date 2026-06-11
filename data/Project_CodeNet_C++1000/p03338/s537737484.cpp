#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,n-1){
        vector<int> x(26), y(26);
        rep(j,i+1) x[s[j]-'a']++;
        
        for(int j = i+1; j < n; j++) y[s[j]-'a']++;
        
        int cnt = 0;
        rep(j,26) if(x[j] > 0 && y[j] > 0) cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}