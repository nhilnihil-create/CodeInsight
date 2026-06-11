#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int n = a.back();

    vector<pair<int, int>> b(N - 1);
    for (int i = 0; i < N - 1; i++) {
        b[i] = { min(a[i], n - a[i]), a[i] };
    }
    sort(b.begin(), b.end());

    int r = b.back().second;

    cout << n << " " << r << endl;

    return 0;
}