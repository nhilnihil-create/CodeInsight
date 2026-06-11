#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int>count(N);
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    count[A-1]++;
  }
  sort(count.begin(),count.end());
  int ans=0;
  for(int i=0;i<N-K;i++){
  ans+=count.at(i);
  }
  cout<<ans<<endl;
  return 0;
}