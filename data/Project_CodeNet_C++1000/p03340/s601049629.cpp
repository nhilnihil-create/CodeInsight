#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 200000;

int main() {
	int n;cin>>n;
	int a[N];
	rep(i,n) cin>>a[i];
	int r=0,s=a[0];
	ll ans=0LL;
	for(int l=0;l<n;l++){
		while(r<n-1&&s+a[r+1]==(s^a[r+1])){
			s+=a[r+1];
			r++;
		}
		ans+=r-l+1;
		if(r<n-1&&l==r){
			s+=a[r+1];
			r++;
		}
		s-=a[l];
	}
	cout<<ans<<endl;
}
