#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> p(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    int highest = *max_element(p.begin(), p.end());
    int pay = accumulate(p.begin(), p.end(), 0);
    pay -= highest / 2;

    cout << pay << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
