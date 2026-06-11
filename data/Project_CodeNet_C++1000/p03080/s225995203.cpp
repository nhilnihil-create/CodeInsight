#include<iostream>
using namespace std;
int main(){
  int n,r = 0,b = 0;char s;cin >> n;
  while(cin >> s){
    if(s=='R') r++;
    else b++;
  }
  cout << ((r>b) ? "Yes":"No") << endl;
}