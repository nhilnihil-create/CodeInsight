#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int arr[N];
    int alice_point = 0;
    int bob_point = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            alice_point += arr[i];
        } else {
            bob_point += arr[i];
        }
    }
    cout << alice_point - bob_point << endl;
}
