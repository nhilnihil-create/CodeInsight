#include "bits/stdc++.h"

using namespace std;

void Main() {
    string N;
    cin >> N;
    bool good = false;
    if ((N[0] == N[1] && N[1] == N[2]) || (N[1] == N[2] && N[2] == N[3])) {
        good = true;
    }
    cout << (good ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
