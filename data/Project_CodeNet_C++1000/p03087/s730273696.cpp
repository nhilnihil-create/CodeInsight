#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
  int N,Q;
  string S;
  cin>>N>>Q>>S;
  vector<int64_t>no(N);
  int64_t sum=0;
  for(int i=0;i<N;i++){
    if(i>0&&S.substr(i-1,2)=="AC"){sum++;}
    no[i]=sum;
  }
  while(Q--){
    int l,r;
    cin>>l>>r;
    l--;r--;
    cout<<no[r]-no[l]<<endl;
  }

  return 0;
}