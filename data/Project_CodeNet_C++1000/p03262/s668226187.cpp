#include <iostream>

#include <vector>

using namespace std;

long long GCD(long long a, long long b) {

    if (b == 0) return a;

    else return GCD(b, a % b);

}

int main() {

    int N; long long X;

    cin >> N >> X;

    vector<long long> x(N); for (int i = 0; i < N; ++i) cin >> x[i], x[i] -= X;

    long long g = abs(x[0]);

    for (int i = 0; i < N; ++i) g = GCD(g, abs(x[i]));

    cout << g << endl;

}