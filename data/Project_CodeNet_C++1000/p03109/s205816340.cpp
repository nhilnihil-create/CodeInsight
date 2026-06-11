#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    if (S[5] == '1' || S[6] - '0' >= 5) cout << "TBD" << endl;
    else cout << "Heisei" << endl;
}