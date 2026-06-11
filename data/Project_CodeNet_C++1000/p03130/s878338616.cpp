#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <limits>
#include <numeric>
#include <type_traits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

ll gcd(ll a, ll b) { //gcdを返す
	if(a == 0){
		return b;
	} else if (b == 0){
		return a;
	} else {
	  if(a < b) return gcd(b, a);
	  ll r;
	  while ((r=a%b)) {
	    a = b;
	    b = r;
	  }
	  return b;
	}
}
ll ketasum(ll n) { //桁の数字全ての和を返す 例: 112 -> 4
	ll sum=0;
	if (n<0) return 0;
	while (n>0) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

typedef pair<ll, ll> pair_t;

bool comp(const pair_t &a, const pair_t &b) {
        return a.first < b.first;
}

void sort2vectors(vector<ll> &av, vector<ll> &bv)
{ // ふたつの配列をまとめてそーと A[2,1] B[3,4] -> 1,4 2,3
        ll n = av.size();
        vector<pair_t> p(n);
        vector<ll> av2(n), bv2(n);
        for (ll i = 0; i < n; i++)
                p[i] = make_pair(av[i], bv[i]);
        sort(p.begin(), p.end(), comp);
        for (ll i = 0; i < n; i++) {
                av2[i] = p[i].first;
                bv2[i] = p[i].second;
        }
        av = av2;
        bv = bv2;
}
ll facctorialMethod(ll k){ //階乗
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}


int main(){
	vl a(6);
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	vl k(4);
	REP(i, 4){
		k[i] = 0;
	}
	REP(i, 6){
		if(a[i] == 1){
			k[0]++;
		} else if(a[i] == 2){
			k[1]++;
		} else if(a[i] == 3){
			k[2]++;
		} else {
			k[3]++;
		}
	}
	if(k[0] == 1 && k[1] == 2 && k[2] == 2 && k[3] == 1){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}