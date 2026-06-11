#include<algorithm>
#include<cstdio>
#include<cstring>
  
const int Maxv = 100010; 
int l[Maxv << 1], r[Maxv << 1], n; 
long long ans; 
  
inline int read(){
    int x = 0, f = 1; 
    char ch = getchar(); 
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1; 
        }
        ch = getchar(); 
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0'; 
        ch = getchar(); 
    }
    return x * f; 
}
  
int main(){
    n = read(); 
    for (int i = 1; i <= n; i++) {
        int L = read(); 
        int R = read(); 
        l[Maxv + R]++; 
        r[Maxv + L]++; 
    }
    l[Maxv]++; 
    r[Maxv]++; 
    for (int i = 1; i < 2 * Maxv; i++) {
        l[i] += l[i - 1]; 
    }
    for (int i = 2 * Maxv - 2; i >= 0; i--) {
        r[i] += r[i + 1]; 
    }
    for (int i = 0; i < 2 * Maxv - 1; i++) {
        ans += std::min(l[i], r[i + 1]) * 2; 
    }
    printf("%lld\n", ans); 
    return 0; 
}