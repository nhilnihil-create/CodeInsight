#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        while (h[i] > 0) {
            for (int j = i; j < n; j++) {
                if (h[j] > 0) {h[j]--;}
                else {break;}
            }
            ret++;
        }
    }

    printf("%d\n", ret);
    return 0;
}