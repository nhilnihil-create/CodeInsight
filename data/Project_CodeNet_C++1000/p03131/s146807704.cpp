#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long a,b,k;
  cin >> k >> a >> b;
  long long res;
  if(k<a)res = k+1;
  else{
    if(a+2>=b)res=k+1;
    else{
      k-=(a-1);
      res = (k/2)*b-(k/2-1)*a+k%2;
    }
  }
  cout << res << endl;

}
int main(){
  solve();
  return 0;
}
