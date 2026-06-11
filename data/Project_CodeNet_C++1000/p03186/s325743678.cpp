#include<iostream>

using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    c = min(c, a+b+1);
    cout << b+c;
}
