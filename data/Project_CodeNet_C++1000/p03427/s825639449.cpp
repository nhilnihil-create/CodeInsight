#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int ans;
bool flag;
int main(){
    cin>>s;
    int l=s.size();
    for(int i=1;i<l;i++) ans+=9;
    for(int i=1;i<l;i++) if(s[i]!='9') flag=1;
    if(!flag) cout<<ans+s[0]-'0'<<endl;
    else  cout<<ans+s[0]-'1'<<endl;
    return 0;

}