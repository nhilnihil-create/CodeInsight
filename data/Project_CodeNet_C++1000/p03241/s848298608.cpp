#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,m;
  cin>>n>>m;
  
  vector<int> A;
  for(int i=1;i*i<=m;i++){
    if(m%i==0){
      A.push_back(i);
      if(i*i!=m) A.push_back(m/i);
    }
  }
  sort(ALL(A));
  
  for(int i=0;i<A.size();i++){
    if(A[i]>=n){
      cout<<m/A[i]<<endl;
      return 0;
    }
  }

  return 0;
}