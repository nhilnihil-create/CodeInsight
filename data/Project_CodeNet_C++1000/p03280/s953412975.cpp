#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, ex, area, r;
    scanf("%d %d", &a, &b);
    area = a*b;
    ex = a+b-1;
    r = area-ex;
    printf("%d\n", r);
  //  printf("In this case,the area is %d square yards.", r);
    return 0;
}