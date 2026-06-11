#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    if (S.length() == 2) cout << S;
    else for (int i = 2; i >= 0; i--) cout << S[i]; 
    cout << endl;
}