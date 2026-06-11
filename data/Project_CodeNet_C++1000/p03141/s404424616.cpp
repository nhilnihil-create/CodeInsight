#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}

const ll INF = 1LL << 60;

//Write From this Line

const int mod = 1e9+7;
int main()
{
	int n ;
	cin >> n ;
	int a[n] , b[n];
	rep(i,n) cin >> a[i] >> b[i] ;
	vector<int> A(n);
	ll ans = 0 ;
	rep(i,n){
		A[i] = a[i] + b[i] ;
		ans -= b[i] ;
	}
	SORT(A);
	rSORT(A);
	rep(i,n){
		if(i%2 == 1) continue; 
		else {
			ans += A[i] ;
		}
	}
	cout << ans << endl;

	//全部一回青木くんに食わせる。
}
