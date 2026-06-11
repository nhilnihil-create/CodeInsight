#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll A,B,K;
  cin>>A>>B>>K;
  for(int i=0;i<K;i++){
    if(i%2==0){
      if(A%2)A--;
      B+=A/2;
      A/=2;
    }
    else{
      if(B%2)B--;
      A+=B/2;
      B/=2;
    }
  }
  cout<<A<<" "<<B<<endl;
  return 0;
}
