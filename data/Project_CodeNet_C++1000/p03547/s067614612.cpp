#include <iostream>

using namespace std;

int main() {
    char X, Y;
    int x, y;

    cin >> X >> Y;

    x = (int)(X);
    y = (int)(Y);

    if(x > y) {
        cout << ">" << endl;
    } else if(x < y) {
        cout << "<" << endl;
    } else {
        cout << "=" << endl;
    }

}