#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    int sum_nb;
    int total = 0;

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        sum_nb = i/10000 + (i%10000)/1000 + (i%1000)/100 + (i%100)/10 + i%10;
        if (a <= sum_nb && sum_nb <= b) {
            total += i;
        }
    }
    cout << total << endl;
    return 0;
}