#include <bits/stdc++.h>
using namespace std;

int wa(int n){
    int ans = 0;
    while(n>0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int main(){
  int n;
  cin >> n;
  int ans,j;
  int min1 = 50;
  for(int i=1;i<n;i++){
      j = n-i;
      ans = wa(i)+wa(j);
      min1 = min(min1,ans);
  }
  cout << min1 << endl;
}