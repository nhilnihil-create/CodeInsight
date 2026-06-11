#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    double sum = 0.0;
    for (int i=0; i<n; ++i) {
        double x; string s;
        cin >> x >> s;
        if (s == "JPY") sum += x;
        else sum += x * 380000;
    }
    cout << sum << endl;
}