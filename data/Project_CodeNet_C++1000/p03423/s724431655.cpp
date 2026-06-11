#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (n - n % 3) / 3; 
    return 0;
}