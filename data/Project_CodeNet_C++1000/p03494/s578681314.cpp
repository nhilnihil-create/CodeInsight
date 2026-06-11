#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int a,ans=0;
  cin >> a;
  int b[a];
  for(int i = 0;i<a;i++) cin >> b[i];
  int mbg = b[0];
  for(int i=0 ;i<a;i++){
    mbg = __gcd(mbg,b[i]);
  }
  while(mbg%2==0){
    mbg /= 2;
    ans++;
  }
  cout << ans << endl;
}