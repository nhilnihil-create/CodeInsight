#include<iostream>
#include<string>

using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int ss=s.size();
    int ts=t.size();

    int crt=-1;
    for(int i=0;i<ss;++i){
        bool f=false;
        for(int j=i;j<i+ts;++j){
            if(j>ss-1){
                f=false;
                break;
            }
            if(s[j]==t[j-i]||s[j]=='?') f=true;
            else{
                f=false;
                break;
            }
        }
        if(f) crt=i;
    }
    
    string ans;
    if(crt==-1) ans="UNRESTORABLE";
    else{
        for(int i=crt;i<crt+ts;++i) s[i]=t[i-crt];
        for(int i=0;i<ss;++i) s[i]=s[i]=='?'?'a':s[i];
        ans=s;
    }

    cout<<ans<<endl;
}