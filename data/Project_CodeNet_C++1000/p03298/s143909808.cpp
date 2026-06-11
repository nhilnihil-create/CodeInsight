// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include<unordered_map>
#include <stack>
#include <random>

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

int main(){
	int n; cin >> n;
	string s; cin >> s;
	map<string, ll> mp;
	for(int i = 0;i < (1<<n); i++){
		int k = 0;
		string t = "", u = "";
		for(int j = 0;j < n; j++){
			if(1&(i >> j)){
				t += s[j];
				k++;
			}
			else{
				u += s[j];
			}
		}
		reverse(all(u));
		t += u + to_string(k);
		if(mp.count(t)) mp[t] += 1;
		else mp[t] = 1;
	}
	s = s.substr(n, n*2);
	reverse(all(s));
	ll ans = 0;
	for(int i = 0;i < (1<<n); i++){
		int k = 0;
		string t = "", u = "";
		for(int j = 0;j < n; j++){
			if(1&(i >> j)){
				t += s[j];
				k++;
			}
			else{
				u += s[j];
			}
		}
		reverse(all(u));
		t += u + to_string(k);
		if(mp.count(t)) {
			ans += mp[t];
		}
	}
	cout << ans << endl;
}
