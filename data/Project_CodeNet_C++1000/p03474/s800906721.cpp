#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int A, B;
    string S;
    cin >> A >> B;
    cin >> S;

    if(S[A] != '-'){
        cout << "No" << endl;
        return 0;
    }

    for(int i=0; i<A; i++){
        if('0' <= S[i] && S[i] <= '9'){
            continue;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i=A+1; i<A+B+1; i++){
        if('0' <= S[i] && S[i] <= '9'){
            continue;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}