#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int a , b;
 cin >> a >> b;
 if(b % a == 0)cout << a + b << endl;
 else cout << b - a << endl;
}