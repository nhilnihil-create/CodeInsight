#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans;
  while(1){
    int a = n /100;
    int b = (n % 100) / 10;
    int c = n % 10;
    if (a == b && b == c) break;
    n++;
  }
  cout << n << endl;
  
  return 0;
}