#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s, t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    
    bool ans=false;
    if(s.size()<t.size()){
        ll flg=0;
        rep(i,0,s.size()){
          if(s[i]==t[i])flg++;
          else if(s[i]<t[i]){ans=true;break;}
        }
        if(flg==s.size()) ans=true;
    }
    if(min(s.size(),t.size())>=1) {
        rep(i,0,min(s.size(),t.size())){
            if(s[i]==t[i])continue;
            else if(s[i]<t[i])ans=true;
        }
    }
    cout << (ans ? "Yes":"No") << endl;
    return 0;
}