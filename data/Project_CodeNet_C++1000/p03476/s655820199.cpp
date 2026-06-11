#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int q;
  cin>>q;
  
  vector<int> A(100010),B(100010);
  for(int i=3;i<100000;i+=2) A[i]=1;
  for(int i=3;i<1000;i+=2){
    if(A[i]==1){
      for(int j=3*i;j<100000;j+=2*i) A[j]=0;
    }
  }
  A[2]=1;
  
  for(int i=3;i<100000;i+=2){
    if(A[i]==1 && A[(i+1)/2]==1) B[i]=1;
  }
  
  vector<int> s(100010);
  s[0]=0;
  rep(i,100000){
    s[i+1]=s[i]+B[i];
  }
  
  int l,r;
  rep(i,q){
    cin>>l>>r;
    cout<<s[r+1]-s[l]<<endl;
  }

  return 0;
}