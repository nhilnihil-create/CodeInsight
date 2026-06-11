#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;

    int n = S.length();

    if (n == 2){
        cout << S << endl;
    }
    else {
        for (int i = n-1; i >= 0; i--){
            cout << S[i];
        }
        cout << endl;
    }
}