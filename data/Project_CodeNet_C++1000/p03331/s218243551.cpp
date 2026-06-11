#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int a) {
    int sum = 0;
    while (a != 0) {
        int x;
        x = a % 10;
        sum = sum + x;
        a = a/10;
    }
    return sum;
}

int main() {

    int N;

    cin >> N;

    int B;
    vector<int> sums;

    for (int i = 1; i < N; i++) {
        B = N - i;
        int x;
        x = sum_of_digits(i) + sum_of_digits(B);
        sums.push_back(x);
    }

    cout << *min_element(sums.begin(), sums.end()) << endl;
}