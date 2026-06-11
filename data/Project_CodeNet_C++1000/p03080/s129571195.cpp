#include <bits/stdc++.h>

using namespace std;

int n;
char a[101];

int main()
{
    int cou = 0;
    scanf("%d",&n);
    scanf("%s",a);
    for(int i = 0;i < n;i++)
        if(a[i] == 'R')
            cou++;
    if(cou > n - cou)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
