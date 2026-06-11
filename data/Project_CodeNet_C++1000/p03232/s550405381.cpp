#include <cstdio>
#include <cstdlib>

using namespace std;

class inverse {
    public:
    inverse(int n, int mod);
    ~inverse();
    long long get_inv(int x);
    long long get_fact(int x);
    long long get_invfact(int x);
    long long get_comb(int x, int y);
    
    private:
    int mod;
    long long* inv;
    long long* fact;
    long long* invfact;
};

inverse::inverse(int n, int mod) : mod(mod) {
    inv = (long long *)malloc(sizeof(long long) * (n + 1));
    fact = (long long *)malloc(sizeof(long long) * (n + 1));
    invfact = (long long *)malloc(sizeof(long long) * (n + 1));
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invfact[i] = invfact[i - 1] * inv[i] % mod;
}

inverse::~inverse() {
    free(inv);
    free(fact);
    free(invfact);
}

long long inverse::get_inv(int x) {
    return inv[x];
}

long long inverse::get_fact(int x) {
    return fact[x];
}

long long inverse::get_invfact(int x) {
    return invfact[x];
}

long long inverse::get_comb(int x, int y) {
    return fact[x] * invfact[y] % mod * invfact[x - y] % mod;
}

const int mod = 1000000007;
int a[100000];
long long sum[100000];

int main() {
    int n, i;
    long long ans = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    inverse inv(n, mod);
    
    for (i = 0; i < n; i++) sum[i] = inv.get_inv(i + 1);
    for (i = 1; i < n; i++) sum[i] = (sum[i] + sum[i - 1]) % mod;
    
    for (i = 0; i < n; i++) ans = (ans + (sum[i] + sum[n - i - 1] - 1) % mod * a[i]) % mod;
    
    printf("%lld\n", ans * inv.get_fact(n) % mod);
    
    return 0;
}
