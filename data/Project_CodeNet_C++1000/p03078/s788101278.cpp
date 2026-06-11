#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
#define MOD 1000000007

int main(){
  ll X,Y,Z,K;
  cin>>X>>Y>>Z>>K;
  vector<ll>A(X);
  vector<ll>B(Y);
  vector<ll>C(Z);
  rep(i,X){cin>>A[i];}
  rep(i,Y){cin>>B[i];}
  rep(i,Z){cin>>C[i];}
  priority_queue<ll>dai;
  rep(i,X){
    rep(j,Y){
      ll p=A[i]+B[j];
      dai.push(p);
    }
  }
  vector<ll>F;
  int g=0;
  while(!dai.empty()){
    ll q=dai.top();dai.pop();
    F.push_back(q);
    g++;
    if(g==K){break;}
  }
  priority_queue<ll>sum;
  rep(i,F.size()){
  	rep(j,Z){
      ll r=F[i]+C[j];
      sum.push(r);
    }
  }
  ll ans=0;
  rep(i,K){
  	ll s=sum.top();sum.pop();
    cout<<s<<endl;
  }  
  
}