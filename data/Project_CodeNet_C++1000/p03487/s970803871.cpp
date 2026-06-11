#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=998244353;

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  map<int,int>k;
  for(int i=0;i<N;i++){
    cin>>a[i];
    k[a[i]]++;
  }
  long long cnt=0;
  for(auto c:k){
    if(c.second<c.first){cnt+=c.second;}
    else{cnt+=c.second-c.first;}
  }
  cout<<cnt<<endl;
  return 0;
}
