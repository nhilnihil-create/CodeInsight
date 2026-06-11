#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(i==k-1)
        {
            char c=s[i];
            putchar(tolower(c));
        }
        else
        cout<<s[i];
    }
    
}