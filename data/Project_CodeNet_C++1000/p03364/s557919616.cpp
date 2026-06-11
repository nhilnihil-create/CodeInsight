#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1) * a % MOD;
	}
}

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

int main(void){
	int n;
	cin>>n;
	vector<string> S;
	string s;
	rep(i,n){
		cin>>s;
		S.push_back(s);
	}
	char A[303][303];
	ll count = 0;
	rep(slide,n){
		rep(i,n){
			rep(j,n){
				A[i][j] = S[(int)((i+slide)%n)][j];
			}
		}
		bool ok = true;
		rep(i,n){
			rep(j,n){
				if(A[i][j] != A[j][i]){
					ok = false;
					break;
				}
			}
			if(!ok) break;
		}
		if(ok) count++;
	}
	cout<<count*n<<endl;
	return 0;
}
