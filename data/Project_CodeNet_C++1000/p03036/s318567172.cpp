#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
   int r , d , x;
   cin >> r >> d >> x;
   for(int i = 0;i < 10;i++){
       x = r * x - d;
       cout << x << endl; 
   }
  }

