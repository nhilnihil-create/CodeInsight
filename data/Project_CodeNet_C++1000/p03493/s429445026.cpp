#include <bits/stdc++.h>
using namespace std;

int main() {
 string s;
 cin >> s;
 int sum = 0;

 if(s.at(0) == '1'){
     sum++;
 }
 if(s.at(1) == '1'){
     sum++;
 }
 if(s.at(2) == '1'){
     sum++;
 }

 cout << sum << endl;
}