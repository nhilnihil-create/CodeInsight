#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define rALL(x) x.rbegin(),x.rend()

using namespace std;
using ll=long long;

int inf=1000000;

bool isprime(int n){
  bool flag=true;
  if(n==1)return false;
  for(ll i=2; i*i<=n; i++){
    if(n%i==0){
      flag = false;
      break;
    }
  }
  return flag;
}

int MAX=100005;

int main(){
  int q;cin>>q;
  vector<int> sumc(MAX);
  sumc[0]=0;
  reps(i,MAX){
    sumc[i]=sumc[i-1];
    if(i%2){
      if(isprime(i) && isprime((i+1)/2))sumc[i]++;
    }
  }
  rep(i,q){
    int l,r;cin>>l>>r;
    cout<<sumc[r]-sumc[l-1]<<endl;
  }

}