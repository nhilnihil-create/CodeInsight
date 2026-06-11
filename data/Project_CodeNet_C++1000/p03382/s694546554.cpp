#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int b = a[0];

    for (int i = 1; i < n-1; i++ ) {
        if (abs(a[i] * 2 - a[n-1]) < abs(b * 2 - a[n-1])) {
            b = a[i];
        }
    }

    cout << a[n-1] << " " << b << endl;
    return 0;
}