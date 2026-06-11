#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
	int N,M;
  cin>>N>>M;
  vector<pair<int,int>>P(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    P[i]=make_pair(a,b);
  }
  sort(P.begin(),P.end());
  
  int64_t sum=0;
  int tag=M;
  for(int i=0;i<N;i++){
    int64_t c=P[i].first,d=P[i].second;
    if(d>=tag){sum+=tag*c;break;}
    else{sum+=c*d;tag-=d;}
  }
  cout<<sum<<endl;
  return 0;
}
