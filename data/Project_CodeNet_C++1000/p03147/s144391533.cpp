#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  vector<int> A(n+1,0);
  rep(i,n) cin>>A[i];
  
  int cnt=0;
  for(int i=0;i<n;i++){
    if(A[i]==0) continue;
    while(A[i]>0){
      cnt++;
      A[i]--;
      for(int j=i+1;j<=n;j++){
        if(A[j]!=0) A[j]--;
        else break;
      }
    }
  }
  
  cout<<cnt<<endl;
  
  return 0;
}