#include<iostream>
using namespace std;
int main(){
  char s;int ok = 15;
  while(cin >> s){
    if(s=='x') ok--;
  }
  cout << ((ok>=8) ? "YES":"NO") << endl;
}