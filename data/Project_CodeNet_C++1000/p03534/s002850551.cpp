#include <iostream>
using namespace std;
#include<string.h>
#include<set>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <cstdio>
#include <cstdlib>
#include<stack>
#include<vector>
char a[510000];
int main()
{
    cin>>a;
    int len=strlen(a);
    int sum1=0;
    int sum2=0;
    int sum3=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='a')
            sum1++;
        else if(a[i]=='b')
            sum2++;
        else
            sum3++;
    }
    int min1=min(sum1,min(sum2,sum3));
    if(sum1-min1<2&&sum2-min1<2&&sum3-min1<2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
