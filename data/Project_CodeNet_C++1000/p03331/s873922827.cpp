#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if(fmod(log10(n),1)==0)cout << 10;
  else cout << n%10+n/10%10+n/100%10+n/1000%10+n/10000%10;
}
