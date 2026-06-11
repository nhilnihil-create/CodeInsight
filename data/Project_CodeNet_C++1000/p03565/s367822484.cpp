#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
string s,t;
int n,m;
vector<string> ans;

void check(int start){
    string res = "";
    rep(i,start){
        if(s[i] =='?' )res += 'a';
        else res += s[i];
        //cout << start << " " << res << endl;
    }
    if(start + m > n)return;
    for(int i = start;i < min(n,start + m);i++){
        if(s[i] == '?'|| s[i] == t[i-start])res += t[i-start];
        else return ;

    }
    for(int i = start + m;i < n;i++){
        if(s[i] == '?')res += 'a';
        else res += s[i];

    }
    ans.push_back(res);
}
signed main(){
    cin >> s;
    cin >> t;
    n = s.size(),m = t.size();
    rep(i,n){
        if(s[i] == t[0] || s[i] == '?'){
            check(i);
        }
    }
    if(ans.size() == 0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout << ans[0] << endl;
    return 0;
}