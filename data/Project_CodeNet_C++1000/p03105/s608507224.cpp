#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",min(b/a,c));
}
