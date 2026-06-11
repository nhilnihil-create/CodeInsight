#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
 
string s;
cin >> s;
if (s.size() == 2){
    cout << s << endl;
}
if (s.size() == 3){
    cout << s[2] << s[1] << s[0] << endl;
}
 
 
 return 0; 
}
