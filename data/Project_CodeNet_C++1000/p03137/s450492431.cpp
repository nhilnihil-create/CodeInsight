#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int>X(M);
  for(int i=0;i<M;i++){
    cin>>X[i];
  }
  sort(X.begin(),X.end());
  vector<int>dis;
  for(int i=1;i<M;i++){
    dis.push_back(X[i]-X[i-1]);
  }
  sort(dis.rbegin(),dis.rend());
  int sum=0;
  for(int i=N-1;i<dis.size();i++){
    sum+=dis[i];
  }
  cout<<sum<<endl;
  return 0;  
}