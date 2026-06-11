#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    string s,t;
    cin >> s >> t;

    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());

    rep(i,s.size()){
        bool flag=true;
        rep(j,t.size()){
            if(s[i+j]==t[j]||s[i+j]=='?') continue;
            flag=false;
        }
        if(flag){
            string ans;
            rep(j,i) ans+=s[j];
            rep(j,t.size()) ans+=t[j];
            for(int j=i+t.size();j<s.size();j++) ans+=s[j];
            reverse(ans.begin(),ans.end());
            rep(i,ans.size()){
                if(ans[i]=='?') cout << 'a';
                else cout << ans[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
}