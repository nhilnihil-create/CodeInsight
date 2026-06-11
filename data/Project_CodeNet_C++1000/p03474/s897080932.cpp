#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    bool post=true;
    for (int i=0; i<A; i++){
        if (!('0' <= S.at(i) && S.at(i) <= '9')){
            cout << "No" << endl;;
            return 0;
        }
    }
    if (S.at(A)!='-'){
        cout << "No" << endl;
        return 0;
    }
    for (int i=A+1; i<S.length(); i++){
        if (!('0' <= S.at(i) && S.at(i) <= '9')){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}