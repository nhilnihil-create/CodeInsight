#include <iostream>

using namespace std;

int main() {
  int n;
  cin>>n;
  long l[90] = {2,1};
  for (int i = 2; i <= n; i++) {
    l[i] = l[i-2]+l[i-1];
  }
  cout<<l[n]<<endl;
  return 0;
}
