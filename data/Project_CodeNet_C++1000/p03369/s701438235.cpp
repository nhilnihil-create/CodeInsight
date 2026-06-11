#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;

template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}

const long long INF = 1LL << 60;


int main(void){
	string s;cin >> s;
	int ans = 700;
	rep(i,3) if(s[i]=='o')ans+=100;
	cout << ans << endl;

	return 0;
}

