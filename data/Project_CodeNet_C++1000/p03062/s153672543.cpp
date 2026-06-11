#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
   int n;
   cin >> n;
   vector<ll> v(n);
   int u=0,d=0;
   ll sum = 0;
   ll mn = 100100100;
   rep(i,n){
      cin >> v[i];
      if (v[i] < 0) d++;
      sum += abs(v[i]);
      if (abs(v[i]) < mn){
         mn = abs(v[i]);
      }
   }
   //cout << sum  << ":" << mn << endl;
   if (d%2 == 0) cout << sum << endl;
   else cout << sum - 2*mn << endl;

}
