#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(8 < a || 8 < b) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }
}