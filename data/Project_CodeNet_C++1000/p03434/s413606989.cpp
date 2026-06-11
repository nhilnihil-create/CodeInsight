#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    int aa = 0;
    int bb = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i = i + 2) {
        aa += arr[i];
    }
    for (int i = 1; i < n; i = i + 2) {
        bb += arr[i];
    }
    cout << aa - bb << "\n";
}










