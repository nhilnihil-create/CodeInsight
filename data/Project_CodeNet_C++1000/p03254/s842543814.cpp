#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    uint N;
    int x;
    cin >> N >> x;

    vector<int> a(N, 0);
    for (auto &c: a) {
        cin >> c;
    }

    sort(a.begin(), a.end());
    int numHappy = 0;
    for (size_t i=0; i<a.size(); ++i) {
        x -= a[i];
        if (x >= 0)  ++numHappy;
        else break;
    }
    if (x > 0) --numHappy;
    cout << numHappy;
}
