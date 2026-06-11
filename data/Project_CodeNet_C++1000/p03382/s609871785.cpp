#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int N,temp=0,ans;
  cin>>N;
  vector<int64_t> S(N);
  for(int i=0;i<N;i++)cin>>S.at(i);
  sort(S.begin(),S.end());
  int k=S.at(N-1);
  for(int i=0;i<N;i++){
    int t=min(k-S.at(i),S.at(i));
    if(t>temp){
      temp=t;
      ans=S.at(i);
    }
  }
  cout<<k<<' '<<ans;
    
      
}
