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
	if(n==3){
		cout<<"2 5 63"<<endl;
		return 0;
	}
	ll memo = 0;
	vector<int> ans;
	rep(i,n/4){
		ans.push_back(6*i+2);
		ans.push_back(6*i+3);
		ans.push_back(6*i+4);
		ans.push_back(6*i+6);
		memo += 1;
	}
	int base = 6*(n/4);
	if(n%4==1){
		if(memo%2 == 0){
			ans.push_back(base + 6);
		}else{
			ans.push_back(base + 3);
		}
	}else if(n%4==2){
		if(memo%2==0){
			ans.push_back(base + 2);
			ans.push_back(base + 4);			
		}else{
			ans.push_back(base + 3);
			ans.push_back(base + 6);
		}

	}else if(n%4==3){
		ans.push_back(base + 2);
		ans.push_back(base + 4);
		if(memo%2==0){
			ans.push_back(base + 6);
		}else{
			ans.push_back(base + 3);
		}
	}else{
		if(memo%2==0){

		}else{
			ans[ans.size()-1] = base + 3;
		}
	}
	rep(i,ans.size()){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
