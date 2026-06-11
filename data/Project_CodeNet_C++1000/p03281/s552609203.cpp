#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int main() {
    int N; cin >> N;
    int res = 0;
    for (int i = 1; i <= N; i += 2) {
        int cur = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cur++;
        }
        if (cur == 8) res++;
    }
    printf("%d\n", res);
    return 0;
}
