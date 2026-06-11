#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n){
		cin >> s[i];
	}
	
	int a = 0;
	int b = 0;
	int ba = 0;
	int ans = 0;
	rep(i,n){
		rep(j,s[i].size()-1){
			if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
		}
		if(s[i][0] == 'B') b++;
		if(s[i][s[i].size()-1] == 'A') a++;
		if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') ba++;
	}
	
	if(ba == a && ba == b && b > 0){
		cout << ans + min(a,b) - 1 << endl;
	}else{
		cout << ans + min(a,b) << endl;
	}
    return 0;
}

