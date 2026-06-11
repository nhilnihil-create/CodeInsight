#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[3];
int main()
{
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    printf("%s",(a[0]==a[1]&&a[1]==a[2])?"Yes":"No");
}