// Foods Loved by Everyone
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int K = 0;
        cin >> K;
        for (int k = 0; k < K; k++) {
            int x;
            cin >> x;
            m[x-1]++;
        }
    }
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (m[i] == N) count++;
    }
    cout << count << endl;
}