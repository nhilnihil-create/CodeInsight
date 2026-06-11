#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = max(max(2 * a - 1, 2 * b - 1), a + b);
    cout << ans << '\n';
    return 0;
}