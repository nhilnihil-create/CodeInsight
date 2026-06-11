#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int n;
  cin >> n;
  if (n%2 == 0) cout << n*n/4 << endl;
  else cout << n/2 *((n+2-1)/2) << endl;




  return 0; 
}

