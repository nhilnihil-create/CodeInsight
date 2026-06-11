#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S[5] == '1') {
        cout << "TBD" << endl;
    }
    else if(S[6] == '4' || S[6] == '3') {
        cout << "Heisei" << endl;
    }
    else if(S[6] == '2' || S[6] == '1') {
        cout << "Heisei" << endl;
    }
    else {
        cout << "TBD" << endl;
    }
}
