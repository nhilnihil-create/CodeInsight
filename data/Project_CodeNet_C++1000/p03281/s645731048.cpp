#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  set<int> s;
  vector<int> A={3,5,7,11,13};
  
  int ans=0;
  for(int i=1;i<4;i++){
    if(27*A[i]<=n) ans++;
  }
  for(int i=0;i<=2;i++){
    for(int j=i+1;j<=3;j++){
      for(int k=j+1;k<=4;k++){
        if(A[i]*A[j]*A[k]<=n) ans++;
      }
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}