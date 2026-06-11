#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double result = 0;
    for (int i=0; i<n; i++) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") {
            result += x;
        } else {
            result += x * 380000.0;
        }
    }
    cout << result << endl;
}