#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
  string a, b;
  string c="No";
 
  cin >> a >> b ;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  
  if(a<b)
    c="Yes";
  cout << c << endl;
  
}