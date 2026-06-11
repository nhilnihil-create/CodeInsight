#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A;
  cin>>A;
  vector<string> R(A);
  rep(i,A)cin>>R[i];
  int b;
  cin>>b;
  vector<string> B(b);
  rep(i,b)cin>>B[i];
  int ans=0;
  rep(i,A){
    int num=0;
    string word=R[i];
    rep(j,A){
      if(word==R[j])num+=1;
    }
    rep(j,b){
      if(word==B[j])num-=1;
    }
    if(ans<num)ans=num;
  }
  cout<<ans<<endl;
  return 0;
}