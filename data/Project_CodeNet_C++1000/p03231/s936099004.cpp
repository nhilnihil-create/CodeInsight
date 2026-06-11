#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	ll N,M;
    string S,T;
  	cin>>N>>M;
  	cin>>S;
  	cin>>T;
  	ll lcm=N*M/gcd(N,M);
  	ll good = 1;
  
  	if(S[0]!=T[0]) good=0; 
  	rep(i,gcd(N,M)-1){
     	if(S[i*N/gcd(N,M)]!=T[i*M/gcd(N,M)]) good=0; 
    }
  
  	if(good) cout<<lcm<<endl;
  	else cout<<-1<<endl;
}