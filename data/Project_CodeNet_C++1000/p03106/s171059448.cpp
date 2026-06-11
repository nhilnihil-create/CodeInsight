#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<N;i++)

signed main(){
  int A,B,K;
  cin>>A>>B>>K;
  vector<int> ans;
  rep(i,101){
    if(A%i==0&&B%i==0){
      ans.push_back(i);
    }
  }
  sort(rbegin(ans),rend(ans));
  cout<<ans[K-1]<<endl;
}