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


ll n,k;

ll cal(vector<ll> &da, ll x){
    ll ret = 0;
    rip(i,n,0) ret += da[i]^x;
    return ret;
}

int main(){
    cin >> n >> k;
    vector<ll> da(n);
    rip(i,n,0) cin >> da[i];
    vector<int> co(40);
    rip(i, 40, 0){
        rip(j,n,0){
            if(da[j] >> i&1) co[i]++; 
        }
    }
    ll cand = 0;
    rip(i,40,0){
        if(co[39-i] <= n/2){
            cand = cand*2+1;
        }
        else{
            cand *= 2;
        }
    }
    // cout << cand << endl;
    // vdeb(co);
    ll now = 1, ans = cal(da, k);
    now <<= 39;
    rip(i,40,0){
        if(k&now){
            ll t = 1, next = 0;
            while(t != now){
                next += t&cand;
                t <<= 1;
            }
            t<<=1;
            // cout << t << endl;
            while(t != (1LL << 40)){
                next += t&k;
                t <<= 1;
            }
            // cout << next MM now << endl;
            chmax(ans, cal(da, next));
        }
        now >>= 1;
    }
    cout << ans << endl;
}