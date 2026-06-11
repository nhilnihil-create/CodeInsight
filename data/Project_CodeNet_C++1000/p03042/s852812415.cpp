#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d",&n);
    a = n/100;
    b = n%100;
    if(b==0&&a<=12&&a>0)printf("MMYY\n");
    else if(a==0&&b<=12&&b>0)printf("YYMM\n");
    else if((a<=12&&b>12)&&(a!=0&&b!=0))printf("MMYY\n");
    else if((a>12&&b<=12)&&(a!=0&&b!=0))printf("YYMM\n");
    else if(a<=12&&b<=12&&(a!=0&&b!=0))printf("AMBIGUOUS\n");
    else printf("NA\n");
    return 0;
}
