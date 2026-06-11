
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
   int a, b, k;
   cin >> a >> b >> k;

   int ans=0, kth=0;
   for(int i=min(a,b); i>=1; i--){
       if(a % i ==0 && b % i == 0) kth++;
       if(kth==k){
           ans = i;
           break;
       }
   }
   cout << ans << endl;

}