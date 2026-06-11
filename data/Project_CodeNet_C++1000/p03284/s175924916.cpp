#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, K;
    cin >> N >> K;
    cout << (N % K == 0 ? 0 : 1) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
