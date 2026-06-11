#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


bool used[256];
int cnt;

void solve(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
		used[s[i]-'a'] = true;
		cnt++;
	}
    if(cnt < 26){
		for(int i = 0; i < 26; i++){
			if(!used[i]){
				cout << s + (char)('a' + i) << endl;
				return;
			}
		}
	}
    string t = s;
	if(next_permutation(s.begin(), s.end())){
		for(int i = 0; i < s.size(); i++){
			cout << s[i];
			if(s[i] != t[i]) break;
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
   
}

int main(){
  solve();
  return 0;
}
