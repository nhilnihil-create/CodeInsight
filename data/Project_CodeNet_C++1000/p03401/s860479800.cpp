#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N + 2);
    vector<int> X(N + 1);

    for(int i = 1; i <= N; i++) cin >> A[i];

    int sum = 0;

    for(int i = 0; i <= N; i++) {
        X[i] = abs(A[i + 1] - A[i]);
        sum += X[i];
    }

    for(int i = 0; i < N; i++) {
        cout << sum - X[i] - X[i + 1] + abs(A[i] - A[i + 2]) << endl;
    }
}