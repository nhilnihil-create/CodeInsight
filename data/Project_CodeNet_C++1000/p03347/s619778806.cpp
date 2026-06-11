#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i){
    cin>>A[i];
  }
  bool can = true;
  if(A[0]!=0) can = false;
  for(int i=0;i<N-1;++i){
    if(A[i+1]>A[i]+1) can = false;
  }
  if(!can) {
    cout<<-1<<endl;
    return 0;
  }
  else{
    ll ans = 0;
    int index = N-1;
    bool find;
    while(index>0){
      ans += A[index];
      find = false;
      for(int j=index-1;j>=0;--j){
        if(A[j]>=A[j+1]){
          index = j;
          find = true;
          break;
        }
      }
      if(find) continue;
      break;
    }
    cout<<ans<<endl;
    return 0;
  }
}

