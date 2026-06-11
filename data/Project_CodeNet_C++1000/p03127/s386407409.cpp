#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int mini = 1000000000;
    for (int i = 0; i < n; i++) {
        mini = min(mini, gcd(a[i], a[0]));
    }

    cout << mini << endl;
}