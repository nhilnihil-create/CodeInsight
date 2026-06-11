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
  for(int64_t h=1;h<=3500;h++){
    for(int64_t n=1;n<=3500;n++){
      int64_t a=(4*h*n-N*n-N*h);
      if(a>0&&N*h*n%a==0&&N*h*n/a>0){
        cout<<h<<" "<<n<<" "<<N*h*n/a<<endl;return 0;
      }
    }
  }
  return 0;  
}