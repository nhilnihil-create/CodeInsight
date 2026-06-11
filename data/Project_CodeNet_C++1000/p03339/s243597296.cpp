#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  string S;
  cin >> N;
  cin >> S;
  ll a[N],b[N];
  b[0]=0;
  if(S[0]=='E'){
    a[0]=1;
    b[0]=0;
  }else{
    a[0]=0;
    b[0]=1;
  }
  for(int i=1;i<N;i++){
    if(S[i]=='E') {
      a[i]=a[i-1]+1;
      b[i]=b[i-1];
    }
    else {
      a[i]=a[i-1];
      b[i]=b[i-1]+1;
    }
  }
  ll ans=a[N-1]-a[0];
  for(int i=0;i<N;i++){
    if(ans>a[N-1]-a[i]+b[i-1]) ans=a[N-1]-a[i]+b[i-1];
  }
  cout << ans << endl;
}
