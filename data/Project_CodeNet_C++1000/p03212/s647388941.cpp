#include <iostream>
using namespace std;

int N;
int ans;
void f(long long n, bool f7, bool f5, bool f3){
  if(n > N) return;
  if(f7 && f5 && f3) ans++;
  f(n*10+7, f7|1, f5, f3);
  f(n*10+5, f7, f5|1, f3);
  f(n*10+3, f7, f5, f3|1);
}
int main() {
  
  cin >> N;
  f(7, true, false, false);
  f(5, false, true, false);
  f(3, false, false, true);
  cout << ans << endl;
  return 0;
}