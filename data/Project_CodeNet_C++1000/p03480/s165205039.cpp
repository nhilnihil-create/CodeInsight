#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S; cin >> S;

	char c = S[S.size()/2];
	int ci = S.size()/2;
	int ans = S.size()/2;
	if(S.size()%2 == 0){
		if(S[ci-1] != c){
			cout << ans << endl;
			return 0;
		}
		ans++;
		int cnt = 1;
		while(ci+cnt < S.size() && S[ci+cnt] == c && S[ci-1-cnt] == c){ ans++; cnt++;}
		cout << ans << endl;
	}else{
		ans++;
		int cnt = 1;
		while(ci+cnt < S.size() && S[ci-cnt] == c && S[ci+cnt] == c){ans++; cnt++;}
		cout << ans << endl;
	}
	

	return 0;

}
