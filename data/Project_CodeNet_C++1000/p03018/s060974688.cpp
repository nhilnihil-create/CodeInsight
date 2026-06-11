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
	string s;
	cin >> s;
	string S = "" ;
	rep(i,s.size()){
		char c = s[i] ;
		if(s[i] == 'A'){
			S.push_back('A');
		} else if (s[i] == 'B'){
			i ++ ;
			if(s[i] =='C'){
				S.push_back('D');
			} else {
				S.push_back(c);
				S.push_back(s[i]);
			}
		} else S.push_back(c);
	}
	s = S ;
	int n = s.size();
	int a_count = 0 ;
	ll ans = 0 ;
	rep(i,n){
		char c =s[i] ;
		if( c == 'A'){
			a_count ++; 
		} else if( c == 'D'){
			ans += a_count;
		} else a_count = 0 ;
	}
	cout << ans << endl;
}
