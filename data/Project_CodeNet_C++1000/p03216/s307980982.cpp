//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <time.h>
#include <stdio.h>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mapa make_pair
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
template<typename T>
void vdeb(std::vector<T> &da) {
	for (int i = 0;i < da.size();i++) {
		if (i == da.size() - 1) std::cout << da[i];
		else std::cout << da[i] << ' ';
	}
	std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
	for (int i = 0;i < da.size();i++) vdeb(da[i]);
	std::cout << std::endl;
}

using namespace std;

string s;
int n,q,k;

ll solve(){
	cin >> k;
	vector<ll> dp(3); //DM D M
	ll ret = 0;
	rip(i,n,0){
		if(i >= k){
			if(s[i-k] == 'D'){
				dp[1]--;
				dp[0] -= dp[2];
			}
			else if(s[i-k] == 'M'){
				dp[2]--;
			}
		}
		if(s[i] == 'D'){
			dp[1]++;
		}
		else if(s[i] == 'M'){
			dp[2]++;
			dp[0] += dp[1];
		}
		else if(s[i] == 'C'){
			ret += dp[0];
		}
	}
	return ret;
}

int main(){
	cin >> n >> s >> q;
	vector<ll> ans(q);
	rip(i,q,0) ans[i] = solve();
	rip(i,q,0) printf("%lld\n",ans[i]);
}