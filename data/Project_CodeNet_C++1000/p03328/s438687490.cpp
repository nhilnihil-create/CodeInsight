#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int a,b;
  cin >> a >> b;
  int ans = (b-a)*(b-a+1)/2;
  ans -= b;
  cout << ans << endl;
  
  return 0; 
}

