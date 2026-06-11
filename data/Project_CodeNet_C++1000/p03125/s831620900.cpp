#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B;
  cin>>A>>B;
  if(B%A==0){
    cout<<A+B<<endl;
  }else{
    cout<<B-A<<endl;
  }
}