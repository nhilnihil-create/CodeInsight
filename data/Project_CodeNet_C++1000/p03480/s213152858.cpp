#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
const int N = 100000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
int a[N];
int main()
{
    string str;
   cin>>str;
    int len=str.length();
    int cnt=0;
    for(int i=1;i<len;i++)
    {
        if(str[i]!=str[i-1])
            a[++cnt]=max(i,len-i);
    }
    int res;
    res=len;
    for(int i=1;i<=cnt;i++)
    {
        res=min(res,a[i]);
    }
    printf("%d\n",res);
    return 0;
}