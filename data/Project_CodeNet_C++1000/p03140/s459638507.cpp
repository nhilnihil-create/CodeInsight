#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    vector<string> s(3);
    rep(i,3)cin>>s[i];
    
    int ans = 0;
    
    rep(i,n){
        if(s[0][i]==s[1][i] && s[0][i]==s[2][i])continue;
        if(s[0][i]==s[1][i] || s[0][i]==s[2][i] || s[2][i]==s[1][i])
            ans += 1;
        else
            ans += 2;
    }
    
    cout << ans << endl;
    return 0;
}