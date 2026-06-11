#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> vec(100);
    int min_ = min(A, B);
    for (int i=1; i <= min_; i++) {
        if (A % i == 0 && B % i == 0) {
            vec.push_back(i);
        }
    }

    sort(vec.begin(), vec.end(), greater<int>());
    cout << vec[K-1] << endl;
    return 0;
}