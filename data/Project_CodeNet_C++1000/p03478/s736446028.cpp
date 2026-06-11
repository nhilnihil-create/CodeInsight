#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,ans=0;
  cin >> a >> b >> c;
  for(int i = 0;i<a+1;i++){
    int sum = 0;
    int j = i;
    while(j>0){
      sum += j%10;
      j /=10;
    }
    if(sum>=b&&sum<=c)ans+=i;
  }
  cout << ans;
}