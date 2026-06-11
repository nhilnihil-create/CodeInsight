#include <bits/stdc++.h>
using namespace std;

int main(){
    string A, B;
    cin >> A >> B;

    if(A.at(0) == B.at(2) && A.at(1) == B.at(1) && A.at(2) == B.at(0)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}