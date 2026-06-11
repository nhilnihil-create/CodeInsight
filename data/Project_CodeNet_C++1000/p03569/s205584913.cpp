#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

string delete_x(string s){
	string res;
	rep(i,s.size()){
		if(s[i]!='x') res+=s[i];
	}
	return res;
}

bool check(string s){
	string t = delete_x(s);
	string rt = t;
	REV(rt);
	if(t==rt) return true; else return false;
}

int main(void) {
	string s; cin >> s;
	int n = s.size();
	if(!check(s)){
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	int i = 0;
	int j = n-1;
	while(i<j){
		if(s[i]==s[j]){
			i++;j--;
			continue;
		}
		if(s[i]=='x'){
			i++;
			ans++;
		}
		if(s[j]=='x'){
			j--;
			ans++;
		}
	}
	cout << ans << endl;
}
