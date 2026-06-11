#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s;
    string t;
    cin>>s>>t;
    (s[2]==t[0] && s[1]==t[1] && s[0]==t[2])?cout<<"YES":cout<<"NO";
}