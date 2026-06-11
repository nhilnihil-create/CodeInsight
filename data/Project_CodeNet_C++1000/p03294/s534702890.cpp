#include <bits/stdc++.h>
using namespace std;
int gcd (int a, int b) {
    while (a!=0 && b!=0) {
        if (a>b) {
            a=a%b;
        }
        else b=b%a;
    }
    return a+b;
}
int a[3009];
int main()
{
    int q,i,n,j,maxx = 0 , summ = 0;
    cin >> n;
    for(i=0;i<n;i++)
    cin>>a[i];
   sort(a , a + n);
   for(i=0;i<n;i++)
   {
       summ += a[i];
   }
   summ-=n;
   cout << summ;
}