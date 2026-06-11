#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,A,B;
  cin >> n >> A >> B;
  int ans=0;
  for(int i=1;i<=n;i++){
    int sum=0;
    int x=i;
    for(int j=0;j<5;j++){
      sum+= x%10;
      x/=10;
    }
    if(A <= sum && sum <=B){
      ans += i;
    }
  }
  cout << ans;
  return 0;
}