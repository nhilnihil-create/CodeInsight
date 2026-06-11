#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    int n2 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
            ++n2;
        }
    }
    cout << n2 << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
