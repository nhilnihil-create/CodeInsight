#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
  int n;
  cin >> n;
  int k = n/100;
  int l = k*111;
  if(n%111 == 0)cout << n << endl;
  else if(n < l)cout << l << endl;
  else cout << l + 111 << endl;
}