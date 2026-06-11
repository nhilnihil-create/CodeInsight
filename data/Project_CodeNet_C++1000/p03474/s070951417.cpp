#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    if(S.length() != A + B + 1 || S[A] != '-'){
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<S.length(); i++){
        if(i != A && S[i] == '-'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}