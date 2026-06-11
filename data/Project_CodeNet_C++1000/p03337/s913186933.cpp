#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){

ll a, b, r1, r2, r3, result;

scanf("%lld %lld", &a, &b);

r1 = a * b;
r2 = a + b;
r3 = a - b;

result = max(r1, r2);
result = max(result, r3);

printf("%lld\n", result);
    return 0;
}