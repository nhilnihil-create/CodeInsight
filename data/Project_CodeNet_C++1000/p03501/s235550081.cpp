#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main(){
  int n,a,b,result;
  cin >> n >> a >> b;
  result = (n*a>b)? b:n*a;
  cout << result << endl;
  return 0;
}