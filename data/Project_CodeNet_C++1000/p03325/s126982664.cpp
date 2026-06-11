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
	ll N;
  	cin>>N;
  	ll a[N];
  	rep(i,N) cin>>a[i];
  	ll count=0;
  	rep(i,N){
     	 while(a[i]%2==0){
          	a[i]/=2;
           	count++;
         }
    }
  
  	cout<<count<<endl;
  
}