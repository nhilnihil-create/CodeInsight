#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, k, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
    d = a-b;
    if(k%2 == 0) printf("%lld\n", d);
    else printf("%lld\n", -d);
}