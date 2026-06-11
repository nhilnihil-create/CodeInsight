#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int k;
 cin >> k;
 int s = k / 2;
 int t = (k + 1) / 2;
 cout << s * t << endl;
}