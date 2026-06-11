#include <bits/stdc++.h>
using namespace std;
string s;
int ans=1e9; 
int main(void){
    cin>>s;
    for(int i=1;i<s.size();++i)
        if(s[i]!=s[i-1]) ans=min(ans,max(i,int(s.length())-i)); 
    cout<<min(ans,int(s.size()))<<"\r\n";
}