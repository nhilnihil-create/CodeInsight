#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

void PrintVec(VI& v) {
    for (Int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return;
}

int main(void) {
    Int n;
    cin >> n;
    VI v(n);
    for (Int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    Int result = 0;
    for (Int i = 0; i < n; ++i) {
        Int target = v[i];
        while (v[i] % 2 == 0) {
            v[i] /= 2;
            ++result;
        }
    }
    cout << result << endl;
    return 0;
}

