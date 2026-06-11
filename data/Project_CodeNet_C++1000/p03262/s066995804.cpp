#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X; scanf("%d%d", &n, &X);
    int x;
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        diff.push_back(abs(X-x));
    }
    sort(diff.begin(), diff.end());
    unique(diff.begin(), diff.end());

    vector<int> dev;
    for (int i = 1; i <= pow(diff[0], 0.5); i++) {
        if (diff[0]%i==0) {
            dev.push_back(i);
            dev.push_back(diff[0]/i);
        }
    }
    sort(dev.begin(), dev.end());
    unique(dev.begin(), dev.end());
    reverse(dev.begin(), dev.end());

    int num = 0;
    int ret = dev[num];
    for (int i = 1; i < diff.size(); i++) {
        while (diff[i] % dev[num] != 0) {num++;}
        ret = dev[num];
        if (ret == 1) break;
    }

    printf("%d\n", ret);
    return 0;
}