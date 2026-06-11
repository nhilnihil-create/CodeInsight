#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(3);
    for (auto &ai: a) cin >> ai;
    sort(a.rbegin(), a.rend());
    cout << (a[0] * 10 + a[1]) + a[2] << endl;
    return 0;
}
