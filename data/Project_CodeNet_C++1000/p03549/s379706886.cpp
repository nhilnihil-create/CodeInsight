#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, M;
    cin >> N >> M;

    cout << (M * 1900 + (N-M) * 100) * pow(2, M) << endl;
}