#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;
    if (n%k == 0){
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
}