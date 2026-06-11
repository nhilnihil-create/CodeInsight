#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch[1000001];
    int sum;
    cin>>ch;
    for(int i=0;i<strlen(ch);i++)
    {
        if(ch[i]=='x')
        {
            sum++;
        }
    }                                           
    if(sum>=8)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}