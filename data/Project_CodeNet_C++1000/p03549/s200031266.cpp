#include<iostream>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int r = 2;
    for (int i = 1; i < m; i++) {
        r *= 2;
    }
    cout << 100 * r * (n - m) + 1900 * r * m << endl;
}