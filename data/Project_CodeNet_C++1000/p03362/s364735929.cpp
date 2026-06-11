#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


vll eratosthenes_sieve(ll N){
	vll table(N+1,0);
	vll prime;
	for(int i=2;i<=N;++i){
		if(table[i]==0){
			prime.push_back(i);
			for(int j=i+i;j<=N;j+=i) table[j]=1;
		}
	}
	return prime;
}

int main(){
  int N;cin>>N;
  vll prime = eratosthenes_sieve(55555);
  vll ans{2};
  int i=1;
  while(ans.size()<N){
    while(prime[i]%5!=2){
      ++i;
    }
    ans.push_back(prime[i]);
    ++i;
  }
  rep(i,N) cout << ans[i] << " ";
  cout <<endl;
}