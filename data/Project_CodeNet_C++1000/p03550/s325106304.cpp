#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2003

int n ,x ,y;
int a[MAX_N];

int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    if(n == 1)
        printf("%d\n",abs(a[0]-y));
    else
        printf("%d\n",max(abs(a[n-1]-y) ,abs(a[n-1]-a[n-2])));
}
