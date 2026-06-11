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

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

ll gcd(ll a, ll b) {
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
ll sum(ll n) {
	ll sum=0;
	if (n<0) return 0;
	while (n>0) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
	ll A, B, K;
	cin >> A >> B >> K;
	for(ll i = 0; i < K; i++){
		if (i % 2 == 0){
			if(A % 2 == 0){
				A /= 2;
				B += A;
			} else {
				A -= 1;
				A /= 2;
				B += A;
			}
		} else {
			if(B % 2 == 0){
				B /= 2;
				A += B;
			} else {
				B -= 1;
				B /= 2;
				A += B;
			}
		}
	}
	cout << A << " " << B << endl;
}