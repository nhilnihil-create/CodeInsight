#include <bits/stdc++.h>
using namespace std;

int g(int x){
  int z=0;
  while(x>0){
    z+=x%10;
    x/=10;
  }
  return z;
}
      
  
int main(){
  int N,A,B;
  cin >> N >> A >> B;
  int ans=0;
  for(int i=1;i<=N;i++){
    if(g(i)>=A&&g(i)<=B){
      ans+=i;
    }
  }
  cout << ans << endl;
}