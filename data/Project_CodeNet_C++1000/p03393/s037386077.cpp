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
	if (s=="zyxwvutsrqponmlkjihgfedcba"){
		cout << -1 << endl;
		return 0;
	}
	int n = s.size();
	int index = -1;
	char m;
	vector<bool> cnt(26,false);
	if (n < 26){
		for(int i = 0; i < n; i++) {
			cnt[s[i] - 'a'] = true;
		}
		for(int i = 0; i < 26; i++) {
			if (cnt[i] == false){
				m = char('a' + i);
				break;
			}
		}
		cout << s << m << endl;
	}
	else{
		for(int i = n - 1; i >= 0; i--) {
			if (s[i] > s[i + 1]){
				cnt[s[i] - 'a'] = true;
			}
			else{
				cnt[s[i] - 'a'] = true;
				for(int j = 0; j < i; j++) {
					cout << s[j];
				}
				for(int j = 25; j >= 0; j--) {
					if (cnt[j] && s[i] - 'a' < j){
						m = char('a' + j);
					}
				}
				cout << m << endl;
				break;

			}
		}
	}
	return 0;
}