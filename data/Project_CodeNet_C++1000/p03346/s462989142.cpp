#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N;
  cin>>N;
  vector<int> v(N);
  for(int i = 0; i < N; i++)cin>>v[i];
  map<int,int> m;
  for(int i = 0; i < N; i++) m[v[i]]=i;
  int t = 1;
  int l = 1,M=0;
  while(t<=N){
    if(t==N) {
      chmax(M,l);
      break;
    }
    else if(m[t]<m[t+1]) {
      t++;
      l++;
    }
    else {
      chmax(M,l);
      t++;
      l=1;
    }
  }
  cout<<N-M<<endl;
}
    