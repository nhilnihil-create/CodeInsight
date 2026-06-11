#include <iostream>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int sum = 0;
  int num = 0;
  rep(i, n){
    int l;
    cin >> l;
    num = max(num, l);
    sum += l;
  }
  if (num < (sum - num)) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}