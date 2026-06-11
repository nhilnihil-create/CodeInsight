#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  
  vector<int> A(n);
  int x,num;
  rep(i,n){
    cin>>x;
    if(x==1) num=i;
    A[i]=x;
  }

  cout<<(n+k-3)/(k-1)<<endl;

  return 0;
}