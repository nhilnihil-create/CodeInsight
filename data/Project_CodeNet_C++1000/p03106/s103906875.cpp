#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, K;
    cin >> A >> B >> K;

    int N = min(A, B);
    vector<int> div;
    for (int i = 1; i <= N; ++i) {
        if (A % i == 0 && B % i == 0) {
            div.push_back(i);
        }
    }
    reverse(div.begin(), div.end());
    cout << div[K - 1] << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
