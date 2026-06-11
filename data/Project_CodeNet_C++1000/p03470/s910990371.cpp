#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> flag(101);
	REP(i, N){
		int input;
		cin >> input;
		flag[input] = 1;
	}
	int ans = 0;
	REP(i, 101){
		ans += flag[i];
	}
	cout << ans << endl;
}
