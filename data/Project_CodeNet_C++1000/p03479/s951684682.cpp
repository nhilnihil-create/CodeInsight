#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
 
int sumdigit(int x){
  if(x/10==0) return x;
  return sumdigit(x/10)+x%10;
  }

int main(){
    
   ll x,y;
   cin >> x>>y;
   int cnt =0;
   while(x<=y){
      x*=2;
      cnt++;
   }
   cout << cnt <<endl;
}