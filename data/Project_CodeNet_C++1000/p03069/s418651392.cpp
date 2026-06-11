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
const int mod = 1e9+7;
//Write From this Line

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> b(n+1);
	b[0] = 0 ;
	rep(i,n){
		if(s[i] == '#'){
			b[i+1] = b[i] + 1;
		} else {
			b[i+1] = b[i];
		}
	}
	int ans = 10010010 ;
	for(int i = 1 ; i <= n ; i++){
		int black = b[i-1] ;
		int white = (n-i) - (b[n]-b[i]);
		chmin(ans,black+white);
	}
	cout << ans << endl;
}
