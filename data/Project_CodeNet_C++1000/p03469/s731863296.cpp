#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    if(S[3] == '7') {
        S[3] = '8';
    }
    cout << S << endl;
}