#include <bits/stdc++.h>
using namespace std; 
int main() {
    string S;
    cin >> S;
    string t1 = S.substr(0, 2) , t2 = S.substr(2);
    int a = stoi(t1), b = stoi(t2);
    if (0 < a && a <= 12) {
        if (0 < b && b <= 12) {
            cout << "AMBIGUOUS" << endl;
        }
        else {
            cout << "MMYY" << endl;
        }
    }
    else {
        if (0 < b && b <= 12) {
            cout << "YYMM" << endl;
        }
        else {
            cout << "NA" << endl;
        }
    }
 
}