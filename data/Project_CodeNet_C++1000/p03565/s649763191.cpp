#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s, t; cin >> s >> t;
    string ans = "";
    for(int i = s.size() - t.size(); i >= 0; i--){
        string tmp = s.substr(i, t.size());
        bool isOK = true;
        for(int i = 0; i < t.size(); ++i){
            if(tmp[i] == '?') continue;
            if(tmp[i] != t[i]) isOK = false;
        }
        //cout << tmp << endl;
        if(isOK){
            ans = s.substr(0,i) + t + s.substr(i+t.size(), s.size()-t.size()-i);
            break;
        }
    }
    if(ans == "") cout << "UNRESTORABLE" << endl;
    else {
        for(int i = 0; i < ans.size(); ++i){
            if(ans[i] == '?') ans[i] = 'a';
        }
        cout << ans << endl;
    }
}