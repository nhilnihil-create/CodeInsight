#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod = 1000000007;

int main() {
  int N;
  cin>>N;
  map<string,int>s;
  map<string,int>t;
  vector<string>S(N);
  for(int i=0;i<N;i++){
    cin>>S[i];
    s[S[i]]++;
  }
  int M;
  cin>>M;
  for(int i=0;i<M;i++){
    string T;
    cin>>T;
    t[T]++;
  }
  int MAX=0;
  for(int i=0;i<N;i++){
    chmax(MAX,s[S[i]]-t[S[i]]);
  }
  cout<<MAX<<endl;
  return 0;
}