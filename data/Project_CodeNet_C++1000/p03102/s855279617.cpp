#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int>B(M);
    for (int i=0; i<M; i++){
        cin >> B.at(i);
    }

    int count = 0;
    for (int i=0; i < N; i++) {
        int res = 0;
        for (int j=0; j<M; j++) {
            int s;
            cin >> s;
            res += s * B[j];
        }

        if (res + C > 0) {
            count += 1;
        }
    }

    cout << count << endl;
    return 0;
}