#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[100002];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);
    int mx = A[n - 1];
    int mid = mx / 2;
    int diff = 1e9, id = 0;
    for(int i = 0; i < n - 1; i++) {
        if(abs(mid - A[i]) <= diff) {
            diff  = abs(mid - A[i]);
            id = A[i];
        }
    }
    cout << mx << " " << id << endl;
}