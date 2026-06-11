#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int64_t N,H;
  cin>>N>>H;
  vector<int64_t>a(N),b(N);
  for(int i=0;i<N;i++){
    cin>>a[i]>>b[i];
  }
  sort(b.rbegin(),b.rend());
  sort(a.rbegin(),a.rend());
  int64_t sum=H;
  int cnt=0;
  for(int i=0;i<N;i++){
    if(b[i]<a[0]){continue;}
    if(H-b[i]<=0){cnt++;H-=b[i];break;}
    else{cnt++;H-=b[i];}
  }
  if(H>0){cnt+=(H+a[0]-1)/a[0];}
  cout<<cnt<<endl;
  return 0;  
}