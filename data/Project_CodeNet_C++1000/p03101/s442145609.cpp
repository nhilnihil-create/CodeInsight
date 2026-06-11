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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();

    int n, m;
    cin >> n >> m;
    int l, c;
    cin >> l >> c;
    cout << n * m - (m * l + (n - l) * c) << '\n';
    return 0;
}