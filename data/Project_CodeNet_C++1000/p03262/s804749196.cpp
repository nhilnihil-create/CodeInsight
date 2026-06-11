#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (a%b == 0) {
        return b;
    } else {
        return gcd(b, a%b);
    }
}
int main() {
    int n, x;
    cin >> n >> x;
    int xi, g;
    cin >> xi;
    g = abs(x-xi);
    for (int i=1; i<n; i++) {
        int xi;
        cin >> xi;
        g = gcd(g, abs(x-xi));
    }
    cout << g << endl;
}