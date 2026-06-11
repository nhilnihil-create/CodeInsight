#include <bits/stdc++.h>
using namespace std;
int f(int n,int k){
    int cnt = 1;
    while(n<k){
        n *= 2;
        cnt *= 2;
    }
    return cnt;
}
int main(){
   long n,k;
   long a = -1,b = 0;
   cin >> n >> k;
   vector<long> v(n);
   for(int i=1;i<n+1;i++){
      if(f(i,k) > a)a = f(i,k);
      v[i-1] = f(i,k);
   }
   for(int i:v){
       b += a/i;
   }
   a *= n;
   double c = (double)b/a;
   cout << fixed << setprecision(13) << c << endl;
 }