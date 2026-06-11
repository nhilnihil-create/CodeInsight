#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep(i,n) for(int i=0;i<n;i++)
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

bool guu(string S){
 int N = sz(S);
  if(N%2 ==1) return false;
  rep(i,N/2){
	if(S[i]!=S[i+(N/2)]) return false;
  }
  return true;
}


int main() {
 int s;
  in(s);
  if(s==25)out("Christmas");
  else if(s==24) out("Christmas Eve");
  else if(s==23) out("Christmas Eve Eve");
  else if(s ==22) out("Christmas Eve Eve Eve");
 }
