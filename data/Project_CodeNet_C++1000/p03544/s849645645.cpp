#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    long long int arr[N + 1];
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            arr[i] = 2;
        } else if (i == 1) {
            arr[i] = 1;
        } else {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }
    cout << arr[N] << endl;
}
