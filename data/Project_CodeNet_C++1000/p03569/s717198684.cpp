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
	string s ;
	cin >> s ;
	int left = 0 ;
	int right = s.size() - 1 ;
	int ans = 0 ;
	while(right > left) {
		if(s[right] == s[left]){
			left ++ ;
			right -- ;
			continue;
		}
		//片方だけx
		if(s[right] == 'x' && s[left] != 'x'){
			right -- ;
			ans ++ ;
			continue;
		}
		if(s[right] != 'x' && s[left] == 'x'){
			left ++;
			ans ++ ;
			continue;
		}
		if(s[right] != s[left] ){
			puts("-1");
			return 0 ;
		}
	}
	cout << ans << endl;

}
