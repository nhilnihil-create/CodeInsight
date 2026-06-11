#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> arr(n + 1, true);
    arr[0] = false;
    arr[1] = false;
    
    for (int i = 2; i * i <= n; i++) {   
        if (!arr[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            arr[j] = false;
        }
    }
    return arr;
}

int main(int argc, char *argv[]) {
    vector<bool> parr = sieve(100000);
    vector<bool> arr2017(100000 + 1, false);
    for (int i = 2; i <= 100000; i++) {
        if (i % 2 == 1 && parr[i] && parr[(i + 1) / 2]) {
            arr2017[i] = true;
        }
    }
    int sum = 0;
    vector<int> sarr(100000 + 1, 0);
    for (int j = 1; j <= 100000; j++) {
        if (arr2017[j]) {
            sum++;
        }
        sarr[j + 1] = sum;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << sarr[r + 1] - sarr[l] << endl;
    }
    return 0;
}
