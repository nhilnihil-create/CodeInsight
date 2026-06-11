#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int N;
  string S;
  cin>>N>>S;
  vector<int>B(N+1);
  vector<int>W(N+1);
  int BC=0,WC=0;
  for(int i=0;i<N;i++){
    if(S[i]=='#'){BC++;}
    if(S[i]=='.'){WC++;}
    B[i+1]=BC;
    W[i+1]=WC;
  }
  int ans=1e9;
  for(int i=0;i<=N;i++){
    int l=B[i],r=W[N]-W[i];
    ans=min(ans,l+r);
  }
  cout<<ans<<endl;
  return 0;
}