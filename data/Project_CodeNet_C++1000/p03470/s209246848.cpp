#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
//------------------------------------------//

int main(){
  int N;cin>>N;
  vector<int> d(N);
  
  rep(i,N) cin>>d[i]; 
  
  sort(d.begin(),d.end());
  
  int cnt=0;
 
  rep(i,N-1){
    if(d[i]<d[i+1]) cnt++;
  }
  cout<<cnt+1<<endl;
}