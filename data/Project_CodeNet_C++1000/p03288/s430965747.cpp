#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r;
    scanf("%d", &r);
    if(r < 1200) printf("ABC\n");
    else if(1200 <= r && r < 2800) printf("ARC\n");
    else printf("AGC\n");
    return 0;
}