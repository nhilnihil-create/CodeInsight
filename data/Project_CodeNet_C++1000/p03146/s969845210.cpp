#include <iostream>
#include<vector>
using namespace std;
int main(void){
   int n;
   cin >> n;
   int ans = 1;
   while(true){
       if(n == 1 || n == 2 || n == 4){
           cout << ans + 3 << endl;
           break;
       }else{
           if(n % 2 == 0){
               n /= 2;
           }else{
               n = 3 * n + 1;
           }
           ans++;
       }
   }
}
