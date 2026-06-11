#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;

#define N 100010

int prime[N];

void eratosthenes(){
  rep(i,N) prime[i]=1;
  prime[0]=prime[1]=0;
  rep(i,N){
    if(prime[i]){
      for(int j=i+i;j<N;j+=i) prime[j]=0;
    }
  }
}


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int q;
  cin>>q;
  int niteru[100010]={};
  eratosthenes();
  rep(i,100010){
    if(prime[i] && prime[(i+1)/2] ) niteru[i]=1;
  }
  rep(i,100009){
    niteru[i+1]+=niteru[i];
  }
						   
  rep(i,q){
    int l,r;
    cin>>l>>r;
    cout<<niteru[r]-niteru[l-1]<<endl;
  }

  return 0;
}