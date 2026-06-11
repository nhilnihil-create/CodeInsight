#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main(){
    scanf("%d%d%d", &n, &a, &b);
    if(1LL * a * b < n || a + b - 1 > n){ puts("-1"); return 0; }
    for(int i = 0, c = n - a, d = 1; i < a; i++){
        for(int j = min(b - 1, c); j >= 0; j--) printf("%d ", d + j);
        d += min(b - 1, c) + 1;
        c = max(0, c - (b - 1));
    }
}