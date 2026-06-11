#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int sumDigit(int n){
      int ans = 0;
      while(n > 0){
            ans += n % 10;
            n /= 10;
      }
      return ans;
}
int main(void){
   int n,a,b;
   cin >> n >> a >> b;
   int ans = 0;
   for(int i = 1;i <= n;i++){
         if(a <= sumDigit(i) && sumDigit(i) <= b){
               ans += i;
         }
   }
   cout << ans << endl;
}
