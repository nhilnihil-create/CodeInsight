#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,k;
int main(){
  cin >> k >> a >> b;
  ll bis = 1;
  if(b-a<=2 || k<=a-1){
    bis = k+1;
  }else{
    bis += a-1;
    k -= (a-1);

    bis += (b-a)*(k/2) + k%2;
  }
  cout << bis << endl;
  return 0;
}
