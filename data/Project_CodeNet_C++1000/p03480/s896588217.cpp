#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string S;
int k[1000000]={0};
int main()
{
    while(cin>>S)
    {  //if(S=="0")return 0;
    int len=S.size();
    int i=0,j;
    int count=0;
    for(j=1;j<len;j++)
     if(S[j]!=S[j-1])
        {
            k[++count]=max(j,len-j);
           // cout<<k[]
        }
     int res=len;
    for(int i=1;i<=count;i++)
        res=min(res,k[i]);

    printf("%d\n",res);

    }
}

