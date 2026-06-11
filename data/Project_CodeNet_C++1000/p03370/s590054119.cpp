#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int>  m(N, 0);

    int sum = 0;
    for (auto &x: m) {
        cin >> x;
        sum += x;
    }

    int num = 0;
    X -= sum;
    num += N;
    sort(m.begin(), m.end());
    num += X / m[0];
    cout << num << endl;
}
