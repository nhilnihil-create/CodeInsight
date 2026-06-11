#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;

int a;
int b;
int c;
int sum=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char s[11];
        cin>>s;
        int len=strlen(s);
        if(s[0]=='B'&&s[len-1]!='A')
        {
            b++;
        }
        if(s[0]!='B'&&s[len-1]=='A')
        {
            a++;
        }
        if(s[0]=='B'&&s[len-1]=='A')
        {
            c++;
        }
        for(int j=0; j<len-1; j++)
        {
            if(s[j]=='A'&&s[j+1]=='B')
            {
                sum++;
            }
        }
    }
     if(c)
    {
        sum+=c-1;
        if(a)a--,sum++;
        if(b)b--,sum++;
    }
    sum+=min(a,b);
    cout<<sum<<endl;
    return 0;
}
