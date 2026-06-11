#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    int result = 0;
    for (int i = 0; i <= N; ++i) {
        if (i % 2 == 0) result += a[i];
        else result -= a[i];
    }
    cout << result << endl;
}