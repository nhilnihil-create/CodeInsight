#include<bits/stdc++.h>
using namespace std;

int main(){
    int S;
    cin >> S;
    if(S%100 > 0 && S%100 < 13) {
        if(S/100 > 0 && S/100 < 13) {
            cout << "AMBIGUOUS" << endl;
        }
        else {
            cout << "YYMM" << endl;
        }
    }
    else if(S/100 > 0 && S/100 < 13) {
        cout << "MMYY" << endl;
    }
    else {
        cout << "NA" << endl;
    }
}