#include <bits/stdc++.h>
 
#define N 200010 
 
using namespace std;
 
typedef long long ll;
 
char *p1, *p2, buf[100000];
 
#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )
 
int rd() {
    int x = 0, f = 1;
    char c = nc();
    while (c < 48) {
        if (c == '-')
            f = -1;
        c = nc();
    }
    while (c > 47) {
        x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
    }
    return x * f;
}
 
ll bin[40];
 
map <ll, int> MP;
 
ll a[N];
 
int main() {
    bin[0] = 1;
    for (int i = 1; i <= 35; i ++ ) {
        bin[i] = bin[i - 1] << 1;
    }
    int n = rd();
    for (int i = 1; i <= n; i ++ ) {
        a[i] = rd();
        MP[a[i]] ++ ;
    }
    sort(a + 1, a + n + 1);
 
    int ans = 0;
    for (int i = n; i; i -- ) {
        if (MP[a[i]] > 0) {
            MP[a[i]] -- ;
            for (int j = 32; j; j -- ) {
                if (bin[j] - a[i] <= a[i] && bin[j] > a[i]) {
                    ll re = bin[j] - a[i];
                    if (MP.count(re) && MP[re] > 0) {
                        MP[re] -- ;
                        ans ++ ;
                        break;
                    }
                }
            }
        }
    }
 
    cout << ans << endl ;
    return 0;
}