#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int N;
  cin>>N;
  int ans=0;
  
  for(int i=1;;i++){
    if(i*i>N){
      ans=(i-1)*(i-1);
      break;
    }
  }
      cout<<ans<<endl;
}