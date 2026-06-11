#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >> S;
    string yea = S.substr(0,4);
    int year = stoi(yea);
    string mont = S.substr(5,2);
    int month = stoi(mont);

    if(month <=4){
        cout << "Heisei" << endl;
    }
    else{
        cout << "TBD" << endl;
    }
}