#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    string s;
    cin>>s;
    
    size_t l=s.length();
    string s01="";
    rep(i,l){
        if(i%2==0) s01=s01+string(1,'1');
        else s01=s01+string(1,'0');
    }
    string s10="";
    rep(i,l){
        if(i%2==0) s10=s10+string(1,'0');
        else s10=s10+string(1,'1');
    }

    int cnt01=0;
    int cnt10=0;
    rep(i,l){
        if(s[i]!=s01[i]) cnt01++;
        if(s[i]!=s10[i]) cnt10++;
    }
    cout<<min(cnt01,cnt10)<<"\n";
    return 0;
}