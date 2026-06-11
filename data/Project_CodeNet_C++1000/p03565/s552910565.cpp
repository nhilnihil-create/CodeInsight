#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s, t;
    cin >> s >> t;
    vector<string> ans;
    ll n = s.size();
    rep(i, 0, n){
        if(i + t.size() - 1 >= n) continue;
        bool f = true;
        string tmp = s;
        rep(j, 0, t.size()){
            tmp[i + j] = t[j];
            if(s[i + j] != t[j] && s[i + j] != '?') f = false;
        }
        if(f) ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    if(ans.empty()) cout << "UNRESTORABLE" << endl;
    else{
        rep(i, 0, n){
            if(ans[0][i] == '?') ans[0][i] = 'a';
        }
        cout << ans[0] << endl;
    }
    return 0;
}