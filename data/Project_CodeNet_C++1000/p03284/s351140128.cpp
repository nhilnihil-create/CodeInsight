#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<class T> T ceil(T a, T b) { return a / b + !!(a % b); }

int main() {
    int a, b; cin >> a >> b;
    cout << ceil(a, b) - a / b << endl;
    return 0;
}
