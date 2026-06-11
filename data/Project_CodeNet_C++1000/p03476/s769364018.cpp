#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+20;
int Q;
int l[MAX_N], r[MAX_N];
vector<int> primes;
vector<int> v;
bool is_prime[MAX_N];

void init()
{
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<MAX_N;++i){
		if(is_prime[i]){
			primes.push_back(i);
			for(ll j=1LL*i*i;j<MAX_N;j+=i) is_prime[j]=false;
		}
	}
	for(int p : primes){
		if(binary_search(primes.begin(),primes.end(), (p+1)/2)){
			v.push_back(p);
		}
	}
}

void solve()
{
	init();
	for(int i=0;i<Q;++i){
		cout<<upper_bound(v.begin(),v.end(),r[i])-lower_bound(v.begin(),v.end(),l[i])<<'\n';
	}
}

int main()
{
	cin >> Q;
	for(int i=0;i<Q;++i) cin >> l[i] >> r[i];
	solve();
	return 0;
}