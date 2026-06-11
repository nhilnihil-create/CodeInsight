#include <iostream>
using namespace std;

#define rep(s, n) for(int i(s); i < n; ++i)

int main() {
    int a(0), b(0);
    cin >> a >> b;
    if(a*b % 2 == 0)
        cout << "Even\n";
    else
        cout << "Odd\n";
    return 0;
}