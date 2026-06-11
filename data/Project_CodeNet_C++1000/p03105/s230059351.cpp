#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int counter = 0;
    int temp = a;
    if (b < a) {
        cout << '0';
    } else {
        while (b >= a) {
            a = a + temp;
            if (counter < c) {
                counter++;
            }
        }
        cout << counter;
    }
}