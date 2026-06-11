#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int ans[N][N];

int main() {
    
    int A, B;
    scanf("%d %d", &A, &B);
    printf("100 100\n");
    for (int i = 51; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            ans[i][j] = 1;
        }
    }
    
    A--;
    B--;
    
    for (int i = 1; i <= 100; i += 2) {
        for (int j = 1; j <= 100; j += 2) {
            if (B == 0) break;
            ans[i][j] = 1;
            B--;
        }
    }
    
    for (int i = 52; i <= 100; i += 2) {
        for (int j = 1; j <= 100; j += 2) {
            if (A == 0) break;
            ans[i][j] = 0;
            A--;
        }
    }
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            printf("%c", (ans[i][j] ? '#' : '.'));
        }
        printf("\n");
    }
    
    return 0;
}