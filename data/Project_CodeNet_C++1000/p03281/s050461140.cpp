#include <bits/stdc++.h>
using namespace std;

int divisor(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ret++;
        }
    }
    return ret;
}

int main(void){

   int N,ans=0;
   cin >> N;
   for(int i=1;i<=N;i=i+2){
       if(divisor(i) == 8) ans++;
   }
   cout << ans << endl;
}