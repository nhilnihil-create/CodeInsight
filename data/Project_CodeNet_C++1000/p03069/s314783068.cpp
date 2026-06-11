#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int black = 0;
	int white = 0;
	
	rep(i,n){
		if(s[i] == '.') white++;
	}
	
	int ans = white;
	
	rep(i,n){
		if(s[i] == '.'){
			white--;
		}
		if(s[i] == '#'){
			black++;
		}
		ans = min(ans ,black + white);
	}
	
	cout << ans << endl;
    return 0;
}