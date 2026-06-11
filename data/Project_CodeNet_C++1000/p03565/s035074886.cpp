#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    string s,t;
    cin >> s >> t;
    int x=s.size(), y=t.size(), res=-1;
    rep(i,x){
        if(s[i]==t[0] || s[i]=='?'){
            bool ok=true;
            for(int j=i; j<i+y; ++j){
                if((s[j]==t[j-i] || s[j]=='?') && x>=y+i){
                    continue;
                }else{
                    ok=false;
                    break;
                }
            }
            if(ok) res=i;
        }
    }
    if(res==-1){
        cout << "UNRESTORABLE" << "\n";
        return 0;
    }else{
        for(int i=res; i<res+y; ++i) s[i]=t[i-res];
        rep(i,x) if(s[i]=='?') s[i]='a';
        cout << s << "\n";
        return 0;
    }
}