#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i, j,
        min = 1000000;
    string a, b;
    for(i = 1; i < n; i++) {
        a = to_string(i);
        b = to_string(n - i);
        int a_sum = 0,
            b_sum = 0;
        for(j = 0; j < (int)a.size(); j++) {
            a_sum += a[j] - '0';
        }
        for(j = 0; j < (int)b.size(); j++) {
            b_sum += b[j] - '0';
        }
        if (min > a_sum + b_sum) {
            min = a_sum + b_sum;
        }
    }
    cout << min << endl;
}
