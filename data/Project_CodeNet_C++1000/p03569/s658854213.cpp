#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	string s;cin>>s;
	vector<int> x(26,0);
	string s1 = "";
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != 'x')s1.pb(s[i]);
	}
	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] != s1[s1.size() - i - 1]){
			cout << -1 << endl;
			return 0;
		}
	}

	int l = 0;
	int r = s.size() - 1;
	vector<char> back;
	int ans = 0;
	while(l != r){
		if(s[l] == s[r]){
			l++;r--;
			if(l > r){
				break;
			}
		}
		else if(s[l] == 'x'){
			l++;
			ans++;
		}
		else{
			r--;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}