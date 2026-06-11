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
	int n;
	cin >> n;
	int l[n];
	rep(i,n) cin >> l[i];
	sort(l,l+n,greater<int>());
	int sum = 0;
	for(int i = 1; i < n; i++) sum += l[i];
	if(sum > l[0]) printf("Yes\n");
	else printf("No\n");

	return 0;
}