#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
 
using namespace std;
 
const int maxn = 350;
 
char a[maxn][maxn];
 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        //printf("%s\n",a[i]);
 
    }
    int sum = 0;
    for(int k=0;k<n;k++)
    {
        bool yes = true;
        for(int i=0;yes&&i<n;i++)
        {
            for(int j=0;yes&&j<n;j++)
            {
                int ii = i+k;
                int jj = j+k;
                if(i+k>=n)
                {
                    ii -= n;
                }
                if(j+k>=n)
                {
                    jj -= n;
                }
                if(a[ii][j] != a[jj][i])
                {
                    yes = false;
                }
            }
        }
        if(yes)
        {
            sum += n;
        }
    }
    printf("%d\n",sum);
    return 0;
}