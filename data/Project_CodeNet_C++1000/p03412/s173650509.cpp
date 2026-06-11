#include <bits/stdc++.h>
using namespace std;
#define all(q) (q).begin(),(q).end()

int main(){
  int N; cin>>N;
  vector<int> A(N),B(N),Ac(N),Bc(N);
  int a=1;
  for(int i=0;i<N;i++)
    cin>>A[i];
  for(int i=0;i<N;i++)
    cin>>B[i];
  vector<int> ans(29,0);
  for(int i=0;i<29;i++){
    for(int j=0;j<N;j++){
      Ac[j]=A[j]%(a*2);
      Bc[j]=B[j]%(a*2);
    }
    sort(all(Bc));
    for(int j=0;j<N;j++){
      ans[i]+=distance(lower_bound(all(Bc),a-Ac[j]),lower_bound(all(Bc),2*a-Ac[j]));
      ans[i]+=distance(lower_bound(all(Bc),3*a-Ac[j]),Bc.end());
      ans[i]%=2;
    }
    a*=2;
  }
  a=1;
  int fl=0;
  for(int i=0;i<29;i++){
    fl+=ans[i]*a;
    a*=2;
  }
  cout<<fl;
}