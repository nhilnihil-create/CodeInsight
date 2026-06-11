#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

int main() {
  long double N;
  cin>>N;
  for(long double h=1;h<=3500;h++){
    for(long double n=1;n<=3500;n++){
      if(4*h*n-N*n-N*h==0){continue;}
       long double w=N*h*n/(4*h*n-N*n-N*h);
        if(w>0&&floor(w)==w){cout<<h<<" "<<n<<" "<<(int64_t)w<<endl;return 0;}
      }
    }
  return 0;
}