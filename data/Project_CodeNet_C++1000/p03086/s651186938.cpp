#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int ans = 0;
    int cnt = 0;
    rep(i, s.length()){
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T')cnt++;
        else cnt=0;
        ans = cnt>ans? cnt: ans;
    }
    
    cout << ans << endl;
}