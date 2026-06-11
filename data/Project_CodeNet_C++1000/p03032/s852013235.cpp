#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;


int main() {
  int N,K;
  cin>>N>>K;
  vector<ll>V(N);
  rep(i,N){
   	cin>>V[i];
  }
  ll maxvalue=0;
  for(int a=0;a<=K;a++){
    for(int b=0;b<=K-a;b++){
    	if(a+b>N){continue;}
    	int p=K-a-b;
      	priority_queue<ll, vector<ll>, greater<ll>> pq;
      	rep(i,a){
        	pq.push(V[i]);
        }
      	rep(i,b){
        	pq.push(V[N-1-i]);
        }
      	rep(i,p){
        	if(!pq.empty()&&pq.top()<0){pq.pop();}
        }
      	ll memo=0;
      	while(!pq.empty()){memo+=pq.top();pq.pop();}
      	maxvalue=max(maxvalue,memo);
    }
  }
  cout<<maxvalue;
}