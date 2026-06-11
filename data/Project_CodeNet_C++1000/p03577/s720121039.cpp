#include <iostream>
#include <string>
using namespace std;

int main () {
    string S;
    cin >> S;

    S.erase(S.length() - 8, S.length());

    cout << S << endl;

    return 0;
}