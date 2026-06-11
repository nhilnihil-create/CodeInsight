#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n;
	ll ans=0;
	cin >>n;
	vector<ll> a(n);
	ll bef;
	rep(i,n){
		cin>>a[i];
	}

	rep(i,n){
		cin>>bef;
		a[i]-=bef;
	}
	sort(all(a));
	rep(i,n){
		if(a[i]<0){
			ans+=(a[i]*-1)/2;
		}else{
			ans-=a[i];
		}
	}

	cout<<solve(ans>=0)<<endl;
}
/*
1 2 3 +2  -> +2
5 2 2  +1  ->-1
-4 0  1 -> -3,-4
-2 0 0

3  1  4  1  5
2  7  1  8  2

1 -6  3 -7  3 -> -6,-13
1  0  0 -7  3
1  0  0 -1  0
3  0  0  0  0


2  7  1  8  2
3  1  4  1  5

-1 6  -3 7  -3
-1 6  -1 5  -1
*/