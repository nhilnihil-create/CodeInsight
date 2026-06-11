#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;

    vector<int> rep;
    if (N == 0) {
        cout << 0 << endl;
        return;
    }
    while (N != 0) {
        int residual = N % (-2);
        if (residual == 0) {
            rep.push_back(0);
        }
        else {
            rep.push_back(1);
            N -= 1;
        }
        N /= (-2);
    }
    reverse(rep.begin(), rep.end());
    for (int i = 0; i < rep.size(); ++i) {
        cout << rep[i];
    }
    cout << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
