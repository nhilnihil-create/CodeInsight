#include<iostream>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    int m[N];
    int sum = 0;
    int min_m = 1000;
    for (int i = 0; i < N; i++) {
        cin >> m[i];
        sum += m[i];
        min_m = min(min_m, m[i]);
    }
    cout << N + (X - sum) / min_m << endl;
}
