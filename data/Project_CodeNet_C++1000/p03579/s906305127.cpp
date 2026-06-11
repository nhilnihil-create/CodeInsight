// #include "pch.h"
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
#include <cassert>
#include <fstream>
#include <stdio.h>
#include<unordered_map>

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

ll n,m;

ll dfs(vector<vector<int>> &da){
	vector<int> ju(n, 0);
	ju[0] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		rip(i, da[now].size(),0){
			if(ju[da[now][i]]){
				if(ju[now] == ju[da[now][i]]) return -1;
			}
			else{
				ju[da[now][i]] = 3 - ju[now];
				q.push(da[now][i]);
			}
		}
	}
	ll ret = 0;
	rip(i,n,0){
		if(ju[i] == 1) ret++;
	}
	return ret;
}

int main(){
	cin >> n >> m;
	vector<vector<int>> da(n, vector<int>(0));
	rip(i,m,0){
		int a,b; cin >> a >> b;
		a--; b--;
		da[a].push_back(b);
		da[b].push_back(a);
	}
	int k = dfs(da);
	if(k == -1) cout << n*(n-1)/2 - m<< endl;
	else cout << k*(n-k)-m << endl;
}