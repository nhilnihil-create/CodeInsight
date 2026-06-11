#include<iostream>
using namespace std;

int main() {
    int n, t, a, h;
    cin >> n >> t >> a;

    int ans = 0;
    int mini = 1<<30;
    for (int i = 0; i < n; i++) {
        cin >> h;
        int tmpe = abs(t * 1000 - h * 6 - a * 1000);
        if (tmpe < mini) {
            ans = i+1;
            mini = tmpe;
        }
    }

    cout << ans << endl;
}