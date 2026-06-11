#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  if(n==0){
    cout<<0<<endl;
    return 0;
  }
  
  vector<int> A;
  while(n!=0){
    if(abs(n)%2==1){
      A.push_back(1);
      n=-(n-1)/2;
    }
    else{
      A.push_back(0);
      n=-n/2;
    }
  }
  reverse(ALL(A));
  rep(i,A.size()) cout<<A[i];
  cout<<endl;
  
  return 0;
}