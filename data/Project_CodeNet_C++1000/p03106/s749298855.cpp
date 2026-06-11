#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
     int imax = max(a, b);
     int cnt = 0;
     for(int i = imax; i >= 1; --i)
     {
         if(a % i == 0 && b % i == 0)
             cnt++;
         if(cnt == k)
         {
             printf("%d\n", i);
             break;
         }
     }
     return 0;
 }