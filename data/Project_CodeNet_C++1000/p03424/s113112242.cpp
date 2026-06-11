#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    set<char> colors;
    for (int i = 0; i < N; ++i) {
        char s;
        cin >> s;
        colors.insert(s);
    }

    cout << (colors.size() == 3 ? "Three" : "Four") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
