#include <bits/stdc++.h>
#include <math.h>

#include <climits>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
//#define local
#ifdef local
#include "dbg-macro/dbg.h"
#endif
//#define hacks
#ifdef hacks
#include <boost/multiprecision/cpp_int.hpp>
#endif
#define p std::pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define pi std::pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rep(i, n) \
	for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
#define vec std::vector
#define oreq |=
#define npm next_permutation
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
ll extgcd(ll a, ll b, ll& x, ll& y);
ll nCr(ll n, ll r);
void stat();
template <typename T>
T fact(T num);
constexpr ll mod = 1000000000 + 7;

int main() {
	stat();
	int a,b,k;cin>>a>>b>>k;
	if(b-a+1<2*k){
#ifdef local
		dbg(1212);
#endif
		for(int i=a;i!=b+1;++i){
			cout<<i<<endl;
		}
		return 0;
	}
	for(int i=a;i<a+k;++i){
		cout<<i<<endl;
	}
	for(int i=b-k+1;i!=+b+1;++i){
		cout<<i<<endl;
	}

	return 0;
}

std::vector<unsigned ll> genprimevec(const unsigned ll N) {
	std::vector<bool> is_prime(N + 1);
	for (unsigned ll i = 0; i <= N; i++) {
		is_prime[i] = true;
	}
	std::vector<unsigned ll> P;
	for (unsigned ll i = 2; i <= N; i++) {
		if (is_prime[i]) {
			for (unsigned ll j = 2 * i; j <= N; j += i) {
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}

void stat(){
#ifdef local
    rep(i, 2){std::cout << "local enable" << std::endl;
}
#endif
#ifdef hacks
rep(i, 2) { std::cout << "boost enable" << std::endl; }
#endif
}

ll nCr(ll n, ll r) {
	ll num = 1;
	for (ll i = 1; i <= r; i++) {
		num = num * (n - i + 1) / i;
	}
	return num;
}

template <typename T>
T fact(T num) {
	if (num == 1) {
		return 1;
	}
	return num * fact(num - 1);
}
