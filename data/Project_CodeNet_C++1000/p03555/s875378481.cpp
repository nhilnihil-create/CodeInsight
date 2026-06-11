#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	string s[2];
	cin >> s[0] >> s[1];
	if(s[0][0] == s[1][2] && s[0][1]==s[1][1] && s[1][0]==s[0][2]){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}