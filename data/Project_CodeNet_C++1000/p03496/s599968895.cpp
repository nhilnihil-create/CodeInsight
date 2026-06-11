#include<iostream>
using namespace std;
typedef long long ll;

const ll INF = 1 << 30;

ll A[55];

int main() {
    int N;
    cin >> N;
    int min_idx = -1, max_idx = -1;
    ll min_A = INF, max_A = -INF;
    bool all_p = true, all_m = true;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (min_A > A[i]) {
            min_idx = i;
            min_A = A[i];
        }
        if (max_A < A[i]) {
            max_idx = i;
            max_A = A[i];
        }
        if (A[i] < 0) all_p = false;
        else all_m = false;
    }
    if (all_p) {
        cout << N - 1 << endl;
        for (int i = 1; i < N; i++) {
            A[i] += A[i - 1];
            cout << i << ' ' << i + 1 << endl;
        }
        /*
        for (int i = 0; i < N; i++) cout << A[i] << ' ';
        cout << endl;
        */
        return 0;
    }
    else if (all_m) {
        cout << N - 1 << endl;
        for (int i = N - 1; i >= 1; i--) {
            A[i - 1] += A[i];
            cout << i + 1 << ' ' << i << endl;
        }
        /*
        for (int i = 0; i < N; i++) cout << A[i] << ' ';
        cout << endl;
        */
        return 0;
    }
    cout << 2 * N - 1 << endl;
    if (max_A > abs(min_A)) {
        for (int i = 1; i <= N; i++) {
            A[i - 1] += A[max_idx];
            cout << max_idx + 1 << ' ' << i << endl;
        }
        for (int i = 1; i < N; i++) {
            A[i] += A[i - 1];
            cout << i << ' ' << i + 1 << endl;
        }
    }
    else {
        for (int i = 1; i <= N; i++) {
            A[i - 1] += A[min_idx];
            cout << min_idx + 1 << ' ' << i << endl;
        }
        for (int i = N; i > 1; i--) {
            A[i - 2] += A[i - 1];
            cout << i << ' ' << i - 1 << endl;
        }
    }
    /*
    for (int i = 0; i < N; i++) cout << A[i] << ' ';
    cout << endl;
    */
    return 0;
}