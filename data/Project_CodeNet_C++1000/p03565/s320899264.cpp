#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL << 60;
const int INF = (1 << 29);

int main(){
    string s; cin >> s;
    string t; cin >> t;
    int n = s.size();
    int m = t.size();
    string tmp = s;

    rep(i,n){
        if(tmp[i]=='?') tmp[i] = 'a';
    }

    vector<string> ans;
    rep(i,n-m+1){
        bool flag = true;
        for(int j=i; j<i+m; j++){
            if(s[j]=='?') continue;
            else if(s[j]!=t[j-i]){
                flag = false;
                // cout << "i " << i << endl;
                // cout << s[j] << " " << t[j] << endl;
                break;
            }
        }
        if(flag){
            string v = tmp;
            string u = v.replace(i,m,t);
            ans.push_back(u);
        }
    }

    sort(ans.begin(), ans.end());
    if(ans.size()==0) cout << "UNRESTORABLE" << endl;
    else cout << ans[0] << endl;
}