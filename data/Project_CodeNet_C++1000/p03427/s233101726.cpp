#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep**(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define out(x) cout<<x<<endl
#define put(x) out(x)
#define in(x) cin>>x
#define maxx(a,b,c) max(a,max(b,c))
#define minn(a,b,c) min(a,min(b,c))
using ll = long long;
using vl = vector<ll>;
using vs = vector<string>;
const double pi = 3.14159265358979;
const ll mod = 1000000007;
int keta(ll N){
  if(N == 0) return 1;
 int a =  log10(N);
  return a+1;
}


int atama(ll N){
  int s = keta (N);
  return N/(pow(10,s-1));
}

int main() {
ll N;
  in(N);
  int s = atama(N);
  int k=keta(N);
  ll ans ;
  
  if(keta(N+1)!=keta(N)) out(9*k);
  else if(s != atama(N+1)) out(9*(k-1)+s);
  else out(9*(k-1)+s-1);
}