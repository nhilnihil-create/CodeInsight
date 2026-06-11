#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  char A,B;
  cin>>A>>B;
  int AA=A-'A';
  int BB=B-'B';
  if(A>B)cout<<">"<<endl;
  else if(A<B)cout<<"<"<<endl;
  else cout<<"="<<endl;
  return 0;
}