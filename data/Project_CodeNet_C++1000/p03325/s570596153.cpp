#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int64_t>vec(N);
    for (int i=0; i < N; i++) {
        cin >> vec.at(i);
    }

    int64_t count = 0;
    for (int i=0; i < N; i++) {
        int64_t num = vec[i];
        while (num % 2 == 0) {
            count += 1;
            num = num / 2;
        }
    }

    cout << count << endl;
    return 0;
}