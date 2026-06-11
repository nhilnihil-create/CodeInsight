#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    string s;
    cin >> s;
    if(s[5] == '0' && (int)(s[6]-48) <= 4){
        cout << "Heisei" <<endl;
    }
    else{
        cout << "TBD" <<endl;
    }
}