#include<iostream>
using namespace std;

int main() {
    int a[1000010];
    cin >> a[0];

    int n = 0;
    while (true) {
        if (a[n] % 2 == 0) a[n+1] = a[n] / 2;
        else a[n+1] = 3 * a[n] + 1;
        n++;

        for (int i = 0; i < n; i++) {
            if (a[n] == a[i]) {
                cout << n + 1 << endl;
                return 0;
            }
        }
    }

}