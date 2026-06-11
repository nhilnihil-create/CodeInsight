#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int a , b;
 cin >> a >> b;
 if(a <= 8 && b <= 8)cout << "Yay!" << endl;
 else cout << ":(" << endl;
}