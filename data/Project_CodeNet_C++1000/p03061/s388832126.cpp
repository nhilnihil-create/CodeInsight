#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    vector<int> L(n, a[0]), R(n, a[n - 1]);

    for(int i = 1; i < n; i++) L[i] = __gcd(L[i - 1], a[i]);
    for(int i = n - 2; i >= 0; i--) R[i] = __gcd(R[i + 1], a[i]);

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) ans = max(ans, R[1]);
        else if(i == n - 1) ans = max(ans, L[n - 2]);
        else ans = max(ans, __gcd(L[i - 1], R[i + 1]));
    }
    printf("%d\n", ans);
}