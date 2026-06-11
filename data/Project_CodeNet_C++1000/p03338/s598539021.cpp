using namespace std;
#include <bits/stdc++.h>
int main(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    for(int i=1;i<n;i++){
        int t=0;
        string a="",b="";
        for(int j=0;j<i;j++)
        a+=s[j];
        for(int j=i;j<s.size();j++)
        b+=s[j];
        int c[26]={};
        for(int j=0;j<a.size();j++)
        c[a[j]-'a']++;
        for(int j=0;j<b.size();j++){
            if(c[b[j]-'a']>0)
            t++;
            c[b[j]-'a']=0;
        }
        if(t>ans)
        ans=t;
    }
    std::cout << ans << std::endl;
}