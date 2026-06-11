#include<bits/stdc++.h>
using namespace std;

int N, A, B;

int main() {
    scanf("%d %d %d", &N, &A, &B);

    if(A + B - 1 > N) {
        printf("-1");
        return 0;
    }
    if(N > 1LL * A * B) {
        printf("-1");
        return 0;
    }
    int pos = N;
    for(int i = 0; i < B; i++) {
        int nxt = max(B - i - 1, pos - A);
        for(int j = nxt + 1; j <= pos; j++) {
            printf("%d ", j);
        }
        pos = nxt;
    }
}
