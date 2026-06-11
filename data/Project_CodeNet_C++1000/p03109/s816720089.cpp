#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 string s;
 cin >> s;
 if(s[5] == '0' && s[6] == '1' || s[5] == '0' && s[6] == '2' || s[6] == '3' || s[6] == '4'){
     cout << "Heisei" << endl;
 }
 else cout << "TBD" << endl;
}
