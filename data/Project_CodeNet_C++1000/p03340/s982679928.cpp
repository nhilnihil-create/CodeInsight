#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n,a[200010];
    long long ans = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    int j = 1;
    long long suma = 0,sumb = 0;
    for (int i = 1; i <= n; i++) {
        while (j <= n && (suma + a[j]) == (sumb ^ a[j])) {
            suma += a[j];
            sumb ^= a[j];
            j++;
        }
        ans += j - i;
        suma -= a[i];
        sumb ^= a[i];
    }
    printf("%lld\n",ans);
    return 0;
}