#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
const int maxn = 100000+10;
char num[maxn];
int main()
{
    while(scanf("%s", num)!=EOF)
    {
        int len=strlen(num);
        int numa=0, numb=0, numc=0;
        for(int i=0; i<len; i++)
        {

            if(num[i]=='a')
            {
                numa++;
            }
            if(num[i]=='b')
            {
                numb++;
            }
            if(num[i]=='c')
            {
                numc++;
            }
        }
            int max_=max(numa, numb);
            max_=max(max_, numc);
            int min_=min(numa, numb);
            min_=min(numc, min_);
            if(max_-min_>1)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
    }
    return 0;
}
