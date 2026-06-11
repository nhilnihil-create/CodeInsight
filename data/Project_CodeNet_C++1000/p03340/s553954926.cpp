#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

int main(){
  int n;
  cin>>n;
  
  vector<int> A(n);
  rep(i,n) cin>>A[i];
  
  int tmp1=0,tmp2=0;
  ll cnt=0;
  int l=0;
  rep(i,n){
    cnt++;
    tmp1+=A[i];
    tmp2^=A[i];
    if(tmp1==tmp2) cnt+=i-l;
    else{
      while(l<i){
        tmp1-=A[l];
        tmp2^=A[l];
        l++;
        if(tmp1==tmp2){
          cnt+=i-l;
          break;
        }
      }
    }
  }
  cout<<cnt<<endl;

  return 0;
}