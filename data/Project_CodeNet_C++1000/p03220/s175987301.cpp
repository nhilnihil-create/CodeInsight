#include <iostream>
using namespace std;
int main() {
    int n;
    double t, a;
    cin >> n >> t >> a;
    int result = 0;
    double minDiff = 1000.0;
    for (int i=1; i<=n; i++) {
        int h;
        cin >> h;
        if (minDiff > abs(t-h*0.006-a)) {
            minDiff = abs(t-h*0.006-a);
            result = i;
        }
    }
    cout << result << endl;
}