#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, k;
    cin >>a >>b >>c >>k;
    cout << ((k%2 == 1) ? b-a : a-b) << endl;
    return 0;
}