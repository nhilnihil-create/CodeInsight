#include<iostream>
using namespace std;

int main() {
    int N, M, X; cin >> N >> M >> X;
    int A[M];
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    int lower_cost = 0;
    int upper_cost = 0;
    for (int i = 0; i < M; i++) {
        if (A[i] > X) {
            upper_cost++;
        } else if (A[i] < X) {
            lower_cost++;
        }
    }
    cout << min(upper_cost, lower_cost) << endl;
}
