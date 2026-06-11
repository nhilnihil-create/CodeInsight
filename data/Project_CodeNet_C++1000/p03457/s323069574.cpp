#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int t[n+1], x[n+1], y[n+1];
    t[0] = x[0] = y[0] = 0;
    int distMinusTime;
    for (int i=1; i<n+1; i++) {
        cin >> t[i] >> x[i] >> y[i];
        distMinusTime = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]) - (t[i]-t[i-1]);
        if (distMinusTime > 0 || distMinusTime%2 != 0) {
            cout << "No" << endl;
            return 0;
        }   
    }
    cout << "Yes" << endl;
}