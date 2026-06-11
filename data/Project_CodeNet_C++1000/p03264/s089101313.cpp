#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;

    int even = K / 2;
    int odd = K - even;
    cout << even * odd << endl;

}