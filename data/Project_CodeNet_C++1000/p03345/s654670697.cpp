#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    long long k;
    scanf("%d%d%d%lld",&a,&b,&c,&k);
    if (k&1) swap(a,b);
    printf("%d",a-b);
}
