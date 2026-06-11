#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0;
    string str;
    cin >> str;

    if (str[0] == 'o')
        count++;
    if (str[1] == 'o')
        count++;
    if (str[2] == 'o')
        count++;

    cout << 700 + (100 * count) << endl;

    return 0;
}