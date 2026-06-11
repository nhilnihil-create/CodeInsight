#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int64_t x;
    cin >> x;
    vector<int64_t>vec(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());
    int ninzu = 0;
    for (int i=0; i<N; i++) {
        if (x >= vec[i]) {
            ninzu = i + 1;
            x -= vec[i];
        } else {
            ninzu = i;
            break;
        }
    }

    if (ninzu == N && x != 0) {
        ninzu -= 1;
    }

    cout << ninzu << endl;
    return 0;
}