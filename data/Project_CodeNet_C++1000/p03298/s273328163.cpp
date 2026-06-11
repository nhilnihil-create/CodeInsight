#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char ch[233];

int n;

map <long long, int> mp;

int main() {
    scanf("%d%s", &n, ch);
    for(int i = 0; i < (1 << n); i++) {
        long long hsh = __builtin_popcount(i);
        for(int j = 0; j < n; j++) if(i >> j & 1) hsh = hsh * 131 + ch[j];
        for(int j = n - 1; j >= 0; j--) if(!(i >> j & 1)) hsh = hsh * 131 + ch[j];
        mp[hsh]++;
    }
    reverse(ch, ch + 2 * n);
    long long ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        long long hsh = __builtin_popcount(i);
        for(int j = 0; j < n; j++) if(i >> j & 1) hsh = hsh * 131 + ch[j];
        for(int j = n - 1; j >= 0; j--) if(!(i >> j & 1)) hsh = hsh * 131 + ch[j];
        ans += mp[hsh];
    }
    printf("%lld\n", ans);
}