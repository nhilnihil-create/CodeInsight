#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    cin>>s;
    int ans=0;
    ans+=stoi(s.substr(0,1))-1;
    for(i=1;i<s.length();i++){
        if(s[i]=='9')count1++;
    }
    if(count1==s.length()-1)ans++;
    ans+=s.length()*9-9;
    cout<<ans<<endl;
}