#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N, T, A;
    cin >> N >> T >> A;
    vector<int> H(N, 0);
    vector<double> diff(N, 0);

    for (size_t i=0; i<H.size(); ++i) {
        cin >> H[i];
        diff[i] = abs((T - H[i] * 0.006) - A);
    }

    auto iter = min_element(diff.begin(), diff.end());
    size_t d = distance(diff.begin(), iter);
    cout << d + 1 << endl;
}
