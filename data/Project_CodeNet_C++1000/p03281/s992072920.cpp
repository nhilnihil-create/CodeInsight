
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
   int n;
   cin >> n;

   int ans=0;
   for(int i=1; i<=n; i+=2){
       int count=0;
       for(int j=1; j<=n; j++){
           if(i%j==0) count++;
       }
       if(count==8) ans++;
   }
   cout << ans << endl;

}