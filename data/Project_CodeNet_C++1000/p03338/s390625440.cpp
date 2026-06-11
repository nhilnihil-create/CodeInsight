#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;

	int ans = 0;
	rep(i,N) {
		string sl = S.substr(0,i);
		string sr = S.substr(i,N-1);

		int al[26] = {0};
		int ar[26] = {0};
		for (char s : sl) al[s-'a']++;
		for (char s : sr) ar[s-'a']++;

		int sum = 0;
		rep(j,26) sum += al[j]*ar[j]>0;
		ans = max(ans,sum);
	}

	cout << ans << endl;
	
	return 0;
}
