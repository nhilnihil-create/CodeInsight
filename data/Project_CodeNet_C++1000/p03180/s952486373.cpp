//#i#include "pch.h"
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

int Pow(int x){
    int ret = 1;
    rip(i,x,0) ret *= 2;
    return ret;
}

int main(){
    int n;cin >> n;
    vector<vector<ll>> da(n,vector<ll>(n));
    rip(i,n,0) rip(j,n,0) cin >> da[i][j];
    vector<ll> dp(Pow(n), 0);
    rip(k,Pow(n),0){
        int now = 1;
        rip(i,n,0){
            if(now&k){
                int now2 = 1;
                rip(j,n,0){
                    if(now2&k) dp[k] += da[i][j];
                    now2 <<= 1;
                }
            }
            now <<= 1;
        }
        //cout << dp[k] << endl;
        vector<int> li(0);
        now = 1;
        rip(i,n,0){
            if(k&now) li.push_back(now);
            now <<= 1;
        }
        rip(i,Pow(li.size()-1),0){
            int look = 1, id = 0;
            rip(j, li.size(),0){
                if(i&look) id |= li[j];
                look <<= 1;
            }
            chmax(dp[k], dp[id]+dp[k^id]);
        }
    }
    //vdeb(dp);
    cout << dp.back()/2 << endl;
}