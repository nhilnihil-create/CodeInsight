#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<char> s(6);
    for(int i=0;i<6;i++)
    cin>>s[i];
    if(s[2]==s[3]&&s[1]==s[4]&&s[0]==s[5])
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}