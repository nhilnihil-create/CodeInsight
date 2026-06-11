#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int n;
 cin >> n;
 if(n < 1200)cout << "ABC" << endl;
 else if(n < 2800)cout << "ARC" << endl;
 else cout << "AGC" << endl;
}