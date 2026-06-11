#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
long double f(long double a,int b){
  if(b==0)return 1;
  if(b%2==0){
    long double t=f(a,b/2);
    return t*t;
  }
  return f(a,b-1)*a;
}

signed main(){
  cout << fixed << setprecision(10);
	int n; cin>>n;
    int k; cin>>k;
	double ans=0;
  rep(i,1,n+1){
    double add=1.0/n;
    int now=i;
    while(now<k){
      now*=2;
      add/=2;
    }
    ans+=add;
  }
  cout<<ans<<endl;
	
	return 0;
}