#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    map<int, int>d;
    for (int i=0; i<N; i++) {
        int K;
        cin >> K;
        for (int j=0; j<K; j++) {
            int num;
            cin >> num;
            if (d.count(num) > 0) {
                d[num] = d[num] + 1;
            } else {
                d[num] = 1;
            }
        }
    }

    int sum = 0;
    for (int i=1; i<=M; i++) {
        if (d[i] == N) {
            sum += 1;
        }
    }

    cout << sum << endl;
    return 0;
}