#include <bits/stdc++.h>
using namespace std;

int A[200009], B[200009];

int main() {
    int N, ans = 0; scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    for(int i=0; i<N; i++) scanf("%d",&B[i]);
    for(int i=0; i<=28; i++) {
        int T = (1 << (i+1));
        sort(A, A+N, [&](int a, int b) { return a % T > b % T; });
        sort(B, B+N, [&](int a, int b) { return a % T < b % T; });
        B[N] = T-1;
        long long s = 0;
        int l = 0, r = -1;
        for(int j=0; j<N; j++) {
            while(r < N && A[j]%T + B[r+1]%T < T) ++r;
            while(l < N && A[j]%T + B[l]%T < T/2) ++l;
            if(l == N) break;
            r = min(r, N-1);
            s += r-l+1;
        }
        l = 0, r = -1;
        for(int j=0; j<N; j++) {
            while(r < N && A[j]%T + B[r+1]%T < 2*T) ++r;
            while(l < N && A[j]%T + B[l]%T < T+T/2) ++l;
            if(l == N) break;
            r = min(r, N-1);
            s += r-l+1;
        }
        if(s % 2) ans += T/2;
    }
    printf("%d",ans);
    return 0;
}
