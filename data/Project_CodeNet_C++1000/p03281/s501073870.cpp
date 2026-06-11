#include <bits/stdc++.h>
using namespace std;

int keta(int x){
  int sum=0;
  while(x>0){
    x/=10;
    sum++;
  }
  return sum;
}

int main() {
  int n,ans=0;
  cin >> n;
  
  for(int i=1;i<=n;i++){
    if(i%2==0)	continue;
    int count=0;
    for(int j=1;j<=i;j++){
      if(i%j==0)	count++;
    }
    if(count==8)	ans++;
  }
  cout << ans;
}
