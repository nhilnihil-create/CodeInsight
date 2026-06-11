#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n,k;
	string s;
	cin >> n >> k;
	cin >> s;
	if(s[k - 1] == 'A'){
		s[k - 1] = 'a';
	}
	else if(s[k - 1] == 'B'){
		s[k - 1] = 'b';
	}
	else s[k - 1] = 'c';
	cout << s << newl;

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
