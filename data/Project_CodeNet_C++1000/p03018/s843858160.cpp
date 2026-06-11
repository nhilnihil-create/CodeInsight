#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

int main() {
  string s;
  cin>>s;
  int n=s.size();

  int cntbc=0;
  int64_t ans=0;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='A'){ans+=cntbc;}
    else if(i-1>=0&&s.substr(i-1,2)=="BC"){cntbc++;i--;}
    else if(i-1>=0&&s.substr(i-1,2)!="BC"){cntbc=0;}
  }
  cout<<ans<<endl;
  return 0;
}