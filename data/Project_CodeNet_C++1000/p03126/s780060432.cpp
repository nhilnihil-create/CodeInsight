//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;
// const int imax = 100000;

int main(){
	int n,m;
	cin >> n >> m;
	int check[m] = {0};
	int k,a;
	rep(i,n){
		cin >> k;
		rep(j,k){
			cin >> a;
			check[a-1]++;
		}
	}
	int ans = 0;
	rep(i,m){
		if(check[i] == n) ans++;
	}
	printf("%d",ans);
	return 0;
}


