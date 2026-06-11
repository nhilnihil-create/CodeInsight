#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main(){
  int N,A,B,p1;
  cin>>N>>A>>B;
  p1=A*N;
  cout<<(p1>=B ? B:p1)<<endl;
}