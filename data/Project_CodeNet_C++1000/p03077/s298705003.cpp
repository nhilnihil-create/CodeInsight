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
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll menor = min(min(min(min(a, b), c), d), e);
    cout << ((n + menor - 1) / menor) + 4 << '\n';
    return 0;
}