#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N, sum = 0;
    cin >> N;
    vector<int> a(N);
    for (auto& i : a) {
        cin >> i;
        sum += i;
    }
    int ans = a.size() - 1, min = 100;
    for (int i = ans; i >= 0; i--) {
        int d = abs(sum - N * a[i]);
        if (d <= min) {
            min = d;
            ans = i;
        }
    }
    cout << ans << endl;
}
