#include <cassert>
#include <cstdio>
using namespace std;

const int B = 1 << 7;
const int sz = 200064 / B * B;

int a[sz];
int b[sz];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", b + i);
    }
    int ans = 0;
    if(N & 1) {
        for(int i = 0; i < N; i++) {
            ans ^= a[i];
            ans ^= b[i];
        }
    }
    for(int i = 0; i < sz; i += B) {
        for(int j = 0; j < sz; j += B) {
            int lim_i = i + B;
            int lim_j = j + B;
            for(int ii = i; ii < lim_i; ii++) {
                for(int jj = j; jj < lim_j; jj++) {
                    ans ^= (a[ii] + b[jj]);
                }
            }
        }
    }
    printf("%d\n", ans);
}