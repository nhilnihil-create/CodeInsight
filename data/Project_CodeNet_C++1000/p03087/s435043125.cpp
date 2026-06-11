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
	ll N,Q;
  	cin>>N>>Q;
  	ll count[N+1]={0};
  	string S;
  	cin>>S;
  	
  	rep(i,N){
     	count[i+1]=count[i]+(S[i]=='A' && S[i+1]=='C'); 
    }
  	
  	rep(i,Q){
     	ll l,r;
      	cin>>l>>r;
      	l--; r--;
      	cout<<count[r]-count[l]<<endl;
    }
  
}