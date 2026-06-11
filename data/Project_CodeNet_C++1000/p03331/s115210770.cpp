#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long calc(int n){
    int res = 0;
    
    while (n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(void){
   long long n;
   cin >> n;
   long long res = 1LL<<60;
   
   for (long long i = 1; i < n; i++){
       long long j = n - i;
       long long temp = calc(i) + calc(j);
       res = min(res,temp);
   }
   cout << res << endl;
}
