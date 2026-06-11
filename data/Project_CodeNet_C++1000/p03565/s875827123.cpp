#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int S=s.size(),T=t.size();
    for(int i=S-T;i>=0;i--){
        if(s[i]==t[0] || s[i]=='?'){
            bool b=1;
            for(int j=0;j<T;j++)if(s[i+j]!='?' && s[i+j]!=t[j])b=0;
            if(b){for(int j=0;j<T;j++)if(s[i+j]=='?')s[i+j]=t[j];
                for(int j=0;j<S;j++)if(s[j]=='?')s[j]='a';
                cout<<s<<endl;
                return 0;
            }
        }
    }
    cout<<"UNRESTORABLE"<<endl;
    return 0;
}