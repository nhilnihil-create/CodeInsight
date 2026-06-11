#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  if((n%2==0&&k<=n/2)||(n%2==1&&k<=n/2+1)) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}