#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    double ans = 0;
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        string u; cin >> u;
        if (u == "JPY") {
            ans += x;
        } else {
            ans += x * 380000;
        }
    }
    cout << ans << endl;
}
