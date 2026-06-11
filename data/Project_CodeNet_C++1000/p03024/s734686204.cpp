#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string S;
    int count = 0;
    
    cin >> S;
    
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'o') {
            count++;
        }
    }
    
    if (count >= 8) {
        cout << "YES" << endl;
    } else {
        if (count + (15 - S.length()) >= 8) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}