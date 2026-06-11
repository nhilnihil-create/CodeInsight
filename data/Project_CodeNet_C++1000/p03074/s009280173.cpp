#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n,k;
	string s;
	cin >> n >> k >> s;
	
	vector<int> people;
	int a = 1;
	char now;
	if(s[0]=='0'){	
		people.push_back(0);
		now = '0';
	}else{
		now = '1';
	}
	FOR(i,1,n){
		if(s[i]==now){
			a++;
		}else{
			people.push_back(a);
			a = 1;
			now = s[i];
		}
	}
	people.push_back(a);
	if(now=='0'){
		people.push_back(0);
	}
	
	
	vector<int> sum((int)people.size()+1);
	sum[0] = 0;
	REP(i,people.size()){
		sum[i+1] = sum[i]+people[i];
	}
	
	
	
	if(k >= (int)people.size()/2){
		cout << n << endl;
		return 0;
	}
	
	k = k*2+1;
	int ans=0;
	for(int i=0; i<(int)sum.size()-k; i+=2){
		chmax(ans, sum[i+k]-sum[i]);
	}
	
	cout << ans << endl;
	return 0;
}