#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int n;
   cin >> n;
   ll now = 0LL;
   map<ll,int> m;
   m[0]++;
   rep(i,n){
      ll tmp;
      cin >> tmp;
      now += tmp;
      m[now]++;
   }
   ll ans = 0LL;
   for (auto w:m){
      //cout << w.first <<" " << w.second << endl;
      ans += ((ll)w.second*(w.second-1)/2LL);
   }
   cout << ans << endl;
   
   return 0;
}
