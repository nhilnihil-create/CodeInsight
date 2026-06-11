#include <iostream>
#include <vector>
using namespace std;
int main(){
  long long n;
  cin >> n;
  vector<long long> s(n+1);
  s[0]=2;
  s[1]=1;
  int i;
  for(i=2;i<=n;i++){
    s[i] = s[i-1] + s[i-2];
  }
  cout << s[n] << "\n";
  return 0;
}