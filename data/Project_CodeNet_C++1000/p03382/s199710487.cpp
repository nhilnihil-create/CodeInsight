#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], r;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++){
        if(abs(a[n - 1] - 2 * a[i]) < abs(a[n - 1] - 2 * r)) r = a[i];
    }
    printf("%d %d\n", a[n - 1], r);
}