#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int n;
    cin >> n;
    vector<Int> c(n);
    vector<Int> s(n);
    vector<Int> f(n);
    for (Int i = 0; i < n; ++i) {
        cin >> c[i] >> s[i] >> f[i];
    }
    Int t;
    for (Int i = 0; i < n; ++i) {
        t = 0;
        for (Int j = i; j < n - 1; ++j) {
            t = max(t, s[j]);
            if (t % f[j] != 0) {
                t += (f[j] - (t % f[j]));
            }
            t += c[j];
        }
        cout << t << endl;
    }
    return 0;
}

