#include<iostream>
#include<string>
using namespace std;
int main(){
  string a;
  cin >> a;
  if (a == "A")
    cout << "T";
  else if (a == "T")
    cout << "A";
  else if (a == "C")
    cout << "G";
  else if (a == "G")
    cout << "C";
}