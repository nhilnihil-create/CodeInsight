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
#include <stack>
#include <set>
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

const int N = 1234567;

ll mpow(ll a, ll b){
	if(b==0) return 1;
	else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
	else return mpow(a,b-1) * a % MOD;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
	if(kaijo_memo.size() > n) return kaijo_memo[n];
	if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
	while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
	return kaijo_memo[n];
}
ll nCr(ll n, ll r){
	if(n < r || r < 0) return 0;
	ll ret = 1;
	ret *= kaijo(n); ret %= MOD;
	ret *= mpow(kaijo(r), MOD-2); ret %= MOD;
	ret *= mpow(kaijo(n-r), MOD-2); ret %= MOD;
	return ret;
}

bool check(vector<int> nums, int k){
	vector<int> dp;
	rep(i,8001){
		dp.push_back(0);
	}
	dp[0] = 1;
	rep(i,nums.size()){
		vector<int> dp2;
		rep(i,8001){
			dp2.push_back(dp[i]);
		}
		rep(j,k+1){
			if(j+nums[i] > k) break;
			dp2[j+nums[i]] = max(dp2[j+nums[i]], dp[j]);
		}
		dp = dp2;
	}
	if(dp[k] == 1) return true;
	else return false;
}

int main(void){
	string s; cin>>s;
	s.push_back('T');
	int x,y; cin>>x>>y;
	vector<int> mx,my;
	int sum_x = 0, sum_y = 0;
	int ri = 0;
	int count = 0;
	rep(i,s.size()){
		char t = s[i];
		if(t == 'F'){
			count++;
		}else{
			if(ri == 0){
				ri = 1;
				x -= count;
			}else if(ri == 2){
				ri = 1;
				mx.push_back(count);
				sum_x += count;
			}else{
				ri = 2;
				my.push_back(count);
				sum_y += count;
			}
			count = 0;
		}
	}
	x = abs(x); y = abs(y);
	if(sum_x%2 != x%2 || sum_y%2 != y%2 || sum_x < x || sum_y < y){
		cout<<"No"<<endl;
		return 0;
	}
	if(check(mx, (sum_x - x) / 2 + x) && check(my, (sum_y - y) / 2 + y)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}
