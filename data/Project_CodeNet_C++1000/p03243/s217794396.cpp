#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = n / 100;
    int b = n % 100 / 10;
    int c = n % 10;

    if (a > b || (a == b && b >= c)) {
        cout << a * 111 << endl;
    } 
    else cout << (a+1) * 111 << endl;
}