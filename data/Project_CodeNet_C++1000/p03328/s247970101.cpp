#include<iostream>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int height = 0;
    for (int i = 1; i <= b - a; i++) {
        height += i;
    }
    cout << height - b << endl;
}
