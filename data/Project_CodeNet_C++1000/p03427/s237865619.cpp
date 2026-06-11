#include<iostream>
#include<cstdio>
using namespace std;
string str;
int sum,f;
int main()
{
    cin>>str;
    for(int i=1;i<str.length();i++) sum += 9;
    for(int i=1;i<str.length();i++) if(str[i]!='9') f=1;
    if(f) cout<<sum+str[0]-'1';
    else cout<<sum+str[0]-'0';
    cout<<endl;
    return 0;
}