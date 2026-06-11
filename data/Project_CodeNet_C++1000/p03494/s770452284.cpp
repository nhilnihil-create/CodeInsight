#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    while(1) {
        bool can_divide = true;
        for (int i = 0; i < N; i++) {
            if (A[i] % 2 != 0) {
                can_divide = false;
            }
        }
        if (can_divide) {
            for (int i = 0; i < N; i++) {
                A[i] /= 2;
            }
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
