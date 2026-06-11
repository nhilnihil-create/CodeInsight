#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    vector<string>ans;
    string s;cin >>s;
    string t;cin >>t;
    for (int i = 0; i < s.size(); ++i) {
        if(i+t.size()>s.size())break;
        bool tmp=true;
        string sub=s.substr(i,t.size());
        for (int j = 0; j < t.size(); ++j) {
            if (sub[j] != '?') {
                if (sub[j] != t[j])tmp = false;
            }
        }
        string k="";
        if(tmp){
            for (int j = 0; j < i; ++j) {
                if(s[j]=='?'){
                    k+='a';
                }
                else {
                    k += s[j];
                }
            }
            k+=t;
            for (int j = i+t.size(); j <s.size(); ++j) {
                if(j>=s.size())break;
                if(s[j]=='?'){
                    k+='a';
                }
                else {
                    k += s[j];
                }
            }
            ans.push_back(k);
        }
    }
    if(ans.empty()){
        puts("UNRESTORABLE");
    } else {
        sort(all(ans));
        cout << ans[0] << endl;
    }
    return 0;
}

