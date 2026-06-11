#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int max_value = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        max_value = max(max_value, p);
        ans += p;
    }
    ans -= max_value / 2;
    cout << ans << endl;
}
