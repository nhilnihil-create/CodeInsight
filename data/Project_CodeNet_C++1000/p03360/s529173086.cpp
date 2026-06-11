#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int a,b,c;
  int k;
  cin >> a >> b >> c;
  cin >> k;

  int ans;
  int mx = max(max(a,b),c);
  if(mx == a) ans = b + c;
  else if(mx == b) ans = a + c;
  else ans = a + b;
  for(int i=0;i<k;i++){
    mx *= 2;
  }

  ans += mx;
  cout << ans << endl;
}