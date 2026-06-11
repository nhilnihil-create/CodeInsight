#include<string>
#include<iostream>
#include<deque>
using namespace std;
using ulli = unsigned long long int;

int main() {
    ulli r, d, x;
    cin >> r >> d >> x;
    for (int i = 1; i <= 10; i++) {
        int temp = x;
        x = r * temp - d;
        cout << x << endl;
    }
    return 0;
}