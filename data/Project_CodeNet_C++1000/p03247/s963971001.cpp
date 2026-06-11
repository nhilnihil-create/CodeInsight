#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char c[5] = "LRDU";
long long x[1000];
long long y[1000];
char ans[1000][41];

int main() {
    int n, i, j, k;
    vector <long long> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%lld %lld", &x[i], &y[i]);
    
    for (i = 1; i < n; i++) {
        if (abs(x[0] + y[0]) % 2 != abs(x[i] + y[i]) % 2) {
            puts("-1");
            
            return 0;
        }
    }
    
    for (i = 35; i >= 0; i--) {
        long long d = (1LL << i);
        
        for (j = 0; j < n; j++) {
            int p = -1;
            long long m = 1e18;
            
            for (k = 0; k < 4; k++) {
                long long t = abs(x[j] + dx[k] * d) + abs(y[j] + dy[k] * d);
                
                if (t < m) {
                    m = t;
                    p = k;
                }
            }
            
            x[j] += dx[p] * d;
            y[j] += dy[p] * d;
            ans[j][v.size()] = c[p];
        }
        
        v.push_back(d);
    }
    
    if (x[0] + y[0] != 0) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < 4; j++) {
                if (abs(x[i] + dx[j]) + abs(y[i] + dy[j]) == 0) {
                    ans[i][v.size()] = c[j];
                    
                    break;
                }
            }
        }
        
        v.push_back(1);
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        printf("%lld", v[i]);
    }
    puts("");
    
    for (i = 0; i < n; i++) printf("%s\n", ans[i]);
    
    return 0;
}
