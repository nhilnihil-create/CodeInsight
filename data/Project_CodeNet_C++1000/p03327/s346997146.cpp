#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int n;
 cin >> n;
 if(n < 1000)cout << "ABC" << endl;
 else cout << "ABD" << endl;
}