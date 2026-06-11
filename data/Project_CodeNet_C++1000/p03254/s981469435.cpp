#include<bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,x,i;
  cin>>N>>x;
  long long ans=0;

  long long a[N];
  for (i=0;i<N;i++)cin>>a[i];
  sort(a,a+N);
  //reverse(a,a+N);
  
  for (i=0;i<N;i++){
    x -= a[i];
    if(x>=0){
      ans++;
    }else{
      break;
    }
  }
  if(x<=0){
    cout << ans << endl;
  }else{
    cout << ans - 1 << endl;
  }
}