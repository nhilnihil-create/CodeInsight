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
	string s;
	cin >> s;
	string t = "keyence";
	int cnt = 0;
	int itr = 0;
	int pre = 0;
	rep(i,int(s.size())){
		for(int j = i - 1; j < int(s.size()); j++){
			string sub = "";
			rep(k,s.size()){
				if(k >= i && k <= j) continue;
				else sub += s[k];
			}
			if(sub == t){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}