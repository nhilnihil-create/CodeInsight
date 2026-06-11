#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    string T,S; 
    cin >> T;
    cin >> S;
    int i = 0;
    if (T == S) {
        cout << "Yes" << endl;
        return 0;
    }
    while(i < T.size()) {
        char lastChar = T[T.size() - 1];
        T = T.substr(0, T.size() - 1);
        T = lastChar + T;
        if (T == S) {
            cout << "Yes" << endl;
            return 0;
        }
        i++;
    }
    cout << "No" << endl;
}
