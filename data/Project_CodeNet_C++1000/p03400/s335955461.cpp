#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
   int n,d,x;
   int ans = 0;
   cin >> n >> d >> x;
   rep(i,n){
      int tmp;
      cin >> tmp;
      int now = 1;
      int id = 0;
      while(now <= d){
         ans++;
         id++;
         now = id*tmp+1;
         
      }
   }
   cout << ans + x << endl;
   return 0;
}

