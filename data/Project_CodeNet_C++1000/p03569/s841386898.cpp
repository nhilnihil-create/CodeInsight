#include<iostream>
using namespace std;
string s;
int l,r,lc,rc,ans;
int main(){
    cin>>s;
    if(s==string(s.size(),'x')){cout<<0<<endl;return 0;}
    for(r=s.size()-1;;lc=rc=0,l++,r--){
        while(s[l]=='x')l++,lc++;
        while(s[r]=='x')r--,rc++;
        if(s[l]!=s[r]){cout<<-1<<endl;return 0;}
        if(r<l)break;
        ans+=abs(lc-rc);
        if(l==r)break;
    }
    cout<<ans<<endl;
    return 0;
}