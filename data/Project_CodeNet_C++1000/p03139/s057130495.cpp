#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void){
  int n,a,b,t;
  cin >> n >> a >> b;
  if (a+b>n) t=a+b-n;
  else t=0;
  cout << min(a,b) << ' ' << t << endl;
  return 0;
}