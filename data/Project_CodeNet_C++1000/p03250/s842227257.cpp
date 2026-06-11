#include <bits/stdc++.h>
using namespace std;
int main()
{
    int maxv = -100, a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if((a * 10 + b) + c > maxv)maxv = (a * 10 + b) + c;
    if((a * 10 + c) + b > maxv)maxv = (a * 10 + c) + b;
    if((b * 10 + a) + c > maxv)maxv = (b * 10 + a) + c;
    if((b * 10 + c) + a > maxv)maxv = (b * 10 + c) + a;
    if((c * 10 + a) + b > maxv)maxv = (c * 10 + a) + b;
    if((c * 10 + b) + a > maxv)maxv = (c * 10 + b) + a;
    if(a + (b * 10 + c) > maxv)maxv = a + (c * 10 + b);
    if(a + (c * 10 + b) > maxv)maxv = a + (c * 10 + b);
    if(b + (a * 10 + c) > maxv)maxv = b + (a * 10 + c);
    if(b + (c * 10 + a) > maxv)maxv = b + (c * 10 + a);
    if(c + (a * 10 + b) > maxv)maxv = c + (a * 10 + b);
    if(c + (b * 10 + a) > maxv)maxv = c + (b * 10 + a);
    printf("%d", maxv);
    return 0;
}