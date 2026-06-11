#include <algorithm>
#include <cstdio>
#include <cstring> 

const int Maxv = 100010; 
const int Mod = 1e9 + 7; 

int inv[Maxv], a[Maxv], ans, n, m; 

int main() {
    scanf("%d", &n); 
    
    inv[1] = 1; 
    for (int i = 2; i <= n; i++)
        inv[i] = 1ll * inv[Mod % i] * (Mod - Mod / i) % Mod; 
    for (int i = 2; i <= n; i++)
        inv[i] = (inv[i - 1] + inv[i]) % Mod; 
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x); 
        ans = (ans + 1ll * x * (inv[i] + inv[n - i + 1] - 1)) % Mod; 
    }
    for (int i = 1; i <= n; i++)
        ans = 1ll * ans * i % Mod; 
    
    printf("%d\n", ans); 

    return 0; 
}