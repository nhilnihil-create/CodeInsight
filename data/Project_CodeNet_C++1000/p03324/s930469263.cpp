#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int d, n; cin >> d >> n;
  int ans = 1;
  for(int i=0; i<d; i++) ans *= 100;
  if(n != 100) ans *= n;
  else ans *= (n+1);
  cout << ans << endl;
    return 0;
}