#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    cout << max(N - K + 1, 0) << endl;
}
