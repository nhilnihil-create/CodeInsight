#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0; i<a; i++)
        if(!(s[i]>='0' && s[i]<='9')){
            puts("No");
            return 0;
        }
    if(s[a]!='-'){
        puts("No");
        return 0;
    }
    for(int i = a+1; i<=a+b; i++)
        if(!(s[i]>='0' && s[i]<='9')){
                puts("No");
                return 0;
        }
    puts("Yes");
    return 0;
}
