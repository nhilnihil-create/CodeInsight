#include "bits/stdc++.h"

using namespace std;

const int MAX = 10000000;

int f(int x) {
    if (x % 2 == 0) {
        return x / 2;
    }
    else {
        return 3 * x + 1;
    }
}

void Main() {
    int s;
    cin >> s;

    set<int> hist;
    hist.insert(s);
    int ans = 0;
    for (int i = 2; i < MAX; ++i) {
        s = f(s);
        if (hist.count(s) == 0) {
            hist.insert(s);
        }
        else {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
