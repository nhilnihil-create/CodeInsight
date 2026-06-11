#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int a[12][12];

int main() {
 int N,K;
 cin>>N>>K;
 vector<int>h(N);
 for(int i=0;i<N;i++){
   cin>>h.at(i);
 }
 sort(h.begin(),h.end());
 int ans=INF;
 for(int i=0;i<=N-K;i++){
  ans=min(ans,h.at(i+K-1)-h.at(i));
 }
  cout<<ans<<endl;
  return 0;
}