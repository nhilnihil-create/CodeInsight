#include<string>
#include<iostream>
#include<deque>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << ((a > 12) ? b : ((a > 5) ? (b / 2) : 0)) << endl;
    return 0;
}