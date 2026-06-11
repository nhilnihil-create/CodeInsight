#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a,b,c,k;
  cin >> a >> b >> c >> k;
  long long int ans;
  if(k%2!=0)
    ans=b-a;
  else
    ans=a-b;
  
  if(ans>1000000000000000000)
    cout << "Unfair" << endl;
  else
    cout << ans << endl;
}