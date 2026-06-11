#include <bits/stdc++.h>
using namespace std;

long long int min(long long int a, long long int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

long long int fivemin(long long int a, long long int b, long long int c,
                      long long int d, long long int e) {
    return min(min(min(a, b), min(c, d)), e);
}

int main() {
    long long int N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;

    long long int output = 0;
    // output = 5;
    // output += N / fivemin(A, B, C, D, E);
    output = 4;
    output += N / fivemin(A, B, C, D, E);
    if (N % fivemin(A, B, C, D, E) != 0) {
        output++;
    }

    cout << output << endl;

    return 0;
}
