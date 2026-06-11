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
	ll k;
	cin >> s;
	cin >> k;
	if(k==1){
		cout << s[0] << endl;
		return 0;
	}else{
		rep(i,s.size()){
			if(s[i]!='1'){
				cout << s[i] << endl;
				return 0;
			}
			if(i+1==k){
				cout << s[i] << endl;
				return 0;
			}
		}
	}
	return 0;
}