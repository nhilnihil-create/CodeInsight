#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;


int main() {
  int N;
  cin>>N;
  vector<int>a(N),b(N),c(N);
  for(int i=0;i<N;i++){cin>>a[i];}
  for(int i=0;i<N;i++){cin>>b[i];}
  for(int i=0;i<N;i++){cin>>c[i];}
  sort(a.begin(),a.end());
  sort(c.begin(),c.end());

  int64_t sum=0;
  for(int i=0;i<N;i++){
    int64_t x=c.end()-upper_bound(c.begin(),c.end(),b[i]);
    int64_t y=lower_bound(a.begin(),a.end(),b[i])-a.begin();
    sum+=x*y;
  }
  cout<<sum<<endl;
  return 0;  
}