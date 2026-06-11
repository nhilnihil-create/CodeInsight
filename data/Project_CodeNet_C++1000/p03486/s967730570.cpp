#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
int main()
{
	string s, t;
	cin >> s >> t;

	SORT(s);
	SORT(t); REV(t);
	if(s < t){
		coY();
	} else {
		coN();
	}
}
