#include <iostream>
#include<vector>
using namespace std;

#define rep(N) for(int i = 0; i < N; i++)
typedef long long ll;

      
int main () {
   int n; cin >> n; 
   vector<ll> a(n);
   rep(n) {
       cin >> a[i];
   }

   ll sum = 0;
   rep(n) {
      if(a[i]%2 == 0) {
         while(a[i]%2 == 0) {
            a[i] /= 2;
            sum ++;
         }
      }
   }

   cout << sum << endl;

}

      

   
