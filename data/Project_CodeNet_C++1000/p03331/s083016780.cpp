#include<bits/stdc++.h>
using namespace std;
int f(int x){
if(x==0) return 0;
  else
    return f(x/10)+(x%10);
}
int main(){
  int N;
  cin>>N; int ans=1000;
  for(int i=1;i<=N/2;i++){
  if(f(i)+f(N-i)<ans)
    ans=f(i)+f(N-i);
  
  }cout<<ans<<endl;
  return 0;
}