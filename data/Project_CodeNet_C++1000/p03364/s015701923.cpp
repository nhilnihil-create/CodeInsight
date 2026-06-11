//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)

int main() {
	ll N;
	// vector<ull> bases = {1000000007, 9973};
	vector<ull> bases = {3, 5};
	cin >> N;
	vector<string> table(N);
	rep(i,0,N) {
		cin >> table[i];
		rep(j,0,N) {
			table[i][j] -= 'a';
		}
	}
	auto hash_pre = make_vec_nd((ull)0, 2, N, N);
	auto hash = hash_pre;
	rep(i,0,2) {
		rep(y,0,N) {
			ull pow = 1;
			ull base = bases[i];
			rep(x,0,N) {
				hash_pre[i][0][y] += pow * (ull)table[y][N-1-x];
				if (x < N-1) {
					pow *= base;
				}
			}
			rep(x,1,N) {
				hash_pre[i][x][y] 
					= base * (hash_pre[i][x-1][y] - pow * (ull)table[y][x-1])
					+ (ull)table[y][(x+N-1)%N];
			}
		}
		rep(x,0,N) {
			ull pow = 1;
			ull base = bases[(i+1)%2];
			rep(y,0,N) {
				hash[i][x][0] += pow * hash_pre[i][x][N-1-y];
				if (y < N-1) {
					pow *= base;
				}
			}
			rep(y,1,N) {
				hash[i][x][y]
					= base * (hash[i][x][y-1] - pow * hash_pre[i][x][y-1])
					+ hash_pre[i][x][(y+N-1)%N];
			}
		}
	}
	ll ans = 0;
	rep(x,0,N) {
		rep(y,0,N) {
			if (hash[0][x][y] == hash[1][x][y]) {
				ans++;
			}
			// cout << "(" << x << "," << y << "): pre " << hash_pre[0][x][y] << " " << hash_pre[1][x][y] << endl;
			// cout << "(" << x << "," << y << "): " << hash[0][x][y] << " " << hash[1][x][y] << endl;
		}
	}
	cout << ans << endl;
}
