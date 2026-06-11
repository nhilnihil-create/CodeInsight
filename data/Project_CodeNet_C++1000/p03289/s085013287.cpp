#include<iostream>
using namespace std;

int main() {
    string S; cin >> S;
    bool willBeAC = true;
    int counter = 0;
    for (int i = 0; i < S.size(); i++) {
        if (i == 0) {
            if (S[0] != 'A') {
                willBeAC = false;
            }
        } else if (i >= 2 && i <= S.size() - 2) {
            if (S[i] == 'C') {
                counter++;
            }
            if (S[i] != 'C' && (S[i] < 97 || S[i] > 122)) {
                willBeAC = false;
            }
        } else {
            if (S[i] < 97 || S[i] > 122) {
                willBeAC = false;
            }
        }
    }
    if (counter != 1) {
        willBeAC = false;
    }
    if (willBeAC) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
}
