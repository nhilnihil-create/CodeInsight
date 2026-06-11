#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, len, w;
    char str[1010];
    scanf("%s", str);
    scanf("%d", &w);
    len = strlen(str);
    for(i = 0; i < len; i += w)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}
