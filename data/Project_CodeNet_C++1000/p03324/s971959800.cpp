#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n; cin >>d >>n;
    cout << setprecision(10) << (pow(100,d) * n + (n==100?pow(100,d):0)) << endl;
    return 0;
}