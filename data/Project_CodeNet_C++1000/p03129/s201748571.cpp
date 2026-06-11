#include<iostream>
#include<string>
using namespace std;

int main(){
  int n,k;
  string out;
  cin >> n >> k;
  if(1+2*(k-1)<=n) out = "YES";
  else out = "NO";
  cout << out << endl;

  return 0;
}