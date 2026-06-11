#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if ((a*b) % 2 == 0) {
        cout << "No";
    }
    
    else {
        cout << "Yes";
    }


    return 0;
}