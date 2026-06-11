#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int64_t N;
  cin>>N;
  int64_t sum=0;
  for(int64_t i=1;i*i<=N;i++){
    int64_t r=N/i;
    if(r-1>0&&N%(r-1)==N/(r-1)){sum+=r-1;}
    if(i-1>0&&N%(i-1)==N/(i-1)){sum+=i-1;}
  }
  cout<<sum<<endl;
  return 0;  
}