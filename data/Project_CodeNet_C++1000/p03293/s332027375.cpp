#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long ll;
using namespace std;

int main(void) {
    string S, T; cin >> S >> T;
    
    for (int i = 0; i < S.length(); i++) {
        char tmp;
        if (S == T) {
            cout << "Yes" << endl;
            return 0;
        }
        tmp = S[S.length()-1];
        S.pop_back();
        S.insert(S.begin(), tmp);
    }
    cout << "No" << endl;
    return 0;
}