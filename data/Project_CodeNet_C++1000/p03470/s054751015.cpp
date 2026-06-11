#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int arr[101] = {0};
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        if (!arr[d]) {
            ans++;
            arr[d] = 1;
        }
    }
    cout << ans << endl;
}
