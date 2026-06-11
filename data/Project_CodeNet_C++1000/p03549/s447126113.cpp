#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double N, M;
    cin >> N >> M;

    int output = (1900 * M + 100 * (N - M)) * pow(2, M);

    cout << output << endl;

    return 0;
}
