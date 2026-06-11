#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int L[N];
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    int n = sizeof(L) / sizeof(L[0]);
    sort(L, L + n);
    int sum = 0;
    bool canMakePolygon = false;
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            if (sum > L[i]) {
                canMakePolygon = true;
            }
        } else {
            sum += L[i];
        }
    }
    if (canMakePolygon) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
