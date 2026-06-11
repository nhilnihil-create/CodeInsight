#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if (S.at(3) != 8) {
        S.at(3) = S.at(3) + 1;
    }
    cout << S << endl;
}
