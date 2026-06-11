#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

ll count(const string &s){
    if(s.size() == 0) return 0;
    int cnt = 0;
    ll ret = 0;
    rep(i,s.size()){
        if(s[i] == ')'){
            ret += i-cnt;
            cnt++;
        }
    }

    return ret;
}

int main(){
    string s;cin>>s;
    string temp = "";
    ll ans = 0;
    rep(i,s.size()){
        if(s[i]=='A') temp.push_back('(');
        else if(i>0 && s[i-1]=='B' && s[i] == 'C'){
            temp.push_back(')');
        }else if(i<s.size()-1&&s[i]=='B'&&s[i+1]=='C') continue;
        else{
            //cout << temp << endl;
            ans += count(temp);
            temp ="";
        }
    }
    if(temp.size()) {
        //cout << temp << endl;
        ans+=count(temp);
    }

    cout << ans << endl;
}