#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl

string S;



int main()
{

	cin >> S;
	int N = S.length();
	if(N == 1){
		cout << "YES";
		return 0;
	} else if (N == 2) {
		if(S[0] != S[1]){
			cout << "YES";
		} else {
			cout << "NO";
		}
		return 0;
	}
	vector <int> a;
	a.resize(3);
	REP(i,N){
		a[S[i]-'a']++;
	}
	sort(a.begin(),a.end());

	int ans[3];
	ans[0] = N/3;
	ans[1] = N/3;
	ans[2] = N/3;

	REP(i,N%3){
		ans[i]++;
	}
	bool flag = true;
	REP(i,3){
		if(a[2-i]!=ans[i])
			flag = false;
	}
	if(flag){
		cout << "YES";
	} else {
		cout << "NO";
	}
}


