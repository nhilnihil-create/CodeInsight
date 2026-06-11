#include<stdio.h>
 typedef long long ll;

 ll a, b;

 ll f(ll x) //从0开始（包括0），每连续的4个数的 异或和 为0
 {
     if(x % 4 == 0)  //位于4个数中的第一位
         return x;
     else if(x % 4 == 1) //位于4个数中的第二位
         return 1;
     else if(x % 4 == 2) //位于4个数中的第三位
         return x + 1;
     else if(x % 4 == 3) //位于4个数中的第四位
         return 0;
 }

 int main()
 {
     scanf("%lld%lld", &a, &b);
     printf("%lld\n", f(b) ^ f(a - 1));
     return 0;
 }