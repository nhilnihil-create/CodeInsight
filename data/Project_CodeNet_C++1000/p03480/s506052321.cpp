#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
char t[100001];
int main()
{
    while(scanf("%s",t)!=EOF)
    {
    int y=strlen(t);
    int max1=y;
    int h=0;
    for(int i=0;i<y;i++)
    {
        if(t[i]!=t[i+1])
        {
            int u;
            if(y-i-1>i+1)
                u=y-i-1;
            else
                u=i+1;
            if(max1>u)
                max1=u;
        }
    }
    cout<<max1<<endl;
    }
    return 0;
}
