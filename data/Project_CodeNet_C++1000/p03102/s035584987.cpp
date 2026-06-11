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

    int n, m, c;
    cin >> n >> m >> c;
    int B[m];
    int tot = 0;
    for (int i = 0; i <= m - 1; i++) cin >> B[i];
    for (int i = 0; i <= n - 1; i++) {
        int tryThis = 0;
        for (int j = 0; j <= m - 1; j++) {
            int a;
            cin >> a;
            tryThis += (a * B[j]);
            //cout << tryThis << '\n';
        }
        tryThis += c;
        if (tryThis > 0) tot++;
    }
    cout << tot << '\n';
    return 0;
}