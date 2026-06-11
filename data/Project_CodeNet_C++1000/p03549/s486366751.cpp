#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    long long correct = n-m;
    long long point = 100*correct + 1900*m;

    double m2 = pow(2, m);
    double y = 1 - 1/m2;

   long long ans = (long long)point/(1-y);

   printf("%lld\n", ans);

   return 0;
    
}