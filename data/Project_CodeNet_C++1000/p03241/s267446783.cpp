#include <bits/stdc++.h>
using namespace std;

int main(void){
   long long n, m;
   cin >> n >> m;
   
   long long ans = 1;
   
   for (long long i = 1; i *i <= m; i++){
       if (m % i != 0) continue;
       
       long long a = i;
       long long b = m / i;
       
       //cout << a << b << endl;
       
       if (a * n <= m) ans = max(ans,a);
       if (b * n <= m) ans = max(ans,b);
   }
   cout << ans << endl;
}

/*
考え方
Mの約数 dのうち、Nd≤Mを満たす最大のdを求めれば良い
*/

/*
corner case: n = 10^5, m = 10^9 (overflow)
time complexity: O(Nsqrt(m))
space complexity: O(1)
*/
