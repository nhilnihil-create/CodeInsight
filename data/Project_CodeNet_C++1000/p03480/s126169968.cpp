#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int a[100005];
    string str;
    cin>>str;
    int len=str.length();
    int cnt=0;
    for(int i=1;i<len;i++)
        if(str[i]!=str[i-1])
            a[++cnt]=max(i,len-i);
    int res=len;
    for(int i=1;i<=cnt;i++)
        res=min(res,a[i]);
    printf("%d\n",res);
    return 0;
}
