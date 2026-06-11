#include <iostream>
using namespace std;

int main(){
    string S;
    cin >> S;

    int size = S.length();

    if (size == 2) cout << S << endl;
    else {
        for (int i = 0; i < 3; i++){
            cout << S[2-i];
        }
        cout << endl;
    }

    return 0;
}