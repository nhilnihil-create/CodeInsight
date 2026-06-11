#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] -= (i+1);
    }

    sort(A.begin(), A.end());

    int cho = A.size()%2 == 0 ? (A[A.size()/2] + A[A.size()/2-1])/2 : A[A.size()/2];
    long long sum = 0;
    long long sum2 = 0;

    for (int i = 0; i < N; ++i) {
        sum += abs(cho - A[i]);
    }

    for (int i = 0; i < N; ++i) {
        sum2 += abs(cho+1 - A[i]);
    }

    cout << sum << endl;

    return 0;
}