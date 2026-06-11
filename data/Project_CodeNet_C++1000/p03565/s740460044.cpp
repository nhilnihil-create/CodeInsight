#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s,t,ans="";
    cin>>s>>t;
    int flag=0;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    std::deque<string> words;
    for (int i=0;i+t.size()<=s.size();i++) {
        ans="";
        string tmp=s.substr(i,t.size());
        flag=0;
        for (int j=0;j<t.size();j++) {
            if (tmp[j]!='?'&&t[j]!=tmp[j]) {
                flag=1;
                break;
            }
        }
        if (flag==0) {
            for (int k=0;k<i;k++) {
                if (s[k]=='?') {
                    ans+='a';
                } else {
                    ans+=s[k];
                }
            }
            ans+=t;
            if (i+t.size()!=s.size()) {
                for (int l=i+t.size();l<s.size();l++) {
                    if (s[l]=='?') {
                        ans+='a';
                    } else {
                        ans+=s[l];
                    }
                }
            }
            reverse(ans.begin(),ans.end());
            words.emplace_back(ans);
        }
    }
    sort(words.begin(),words.end());
    if (words.size()!=0) {
        cout<<words[0]<<endl;
    } else {
        cout<<"UNRESTORABLE"<<endl;
    }
}
