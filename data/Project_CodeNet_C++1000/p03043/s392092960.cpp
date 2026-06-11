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
  int c=0;
  long double ans=0;
  long double a=0;
  if(n>=k){
    a+=(long double)(n-k+1)/n;
   // cout<<n-k+1<<" "<<n<<endl;
   // cout<<"a:"<<a<<endl;
  }
  rep(i,1,n+1){
    if(i>=k)break;
    int j=i;
    int cnt=0;
    while(j<k){
      j*=2;
      cnt++;
    }
    //cout<<cnt<<endl;
    ans+=f(0.5,cnt)/n;
  }
  cout<<ans+a<<endl;
  	
	
      
      
 	
  
	
	
	return 0;
}