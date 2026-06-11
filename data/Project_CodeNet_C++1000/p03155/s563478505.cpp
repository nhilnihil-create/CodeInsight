#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    printf("%d\n",(n-x+1)*(n-y+1));
    return 0;
}
