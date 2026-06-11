#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N; cin >> N;
	string s;
	cin >> s;
	int red = 0, blue = 0;

	rep(i, s.size()){
		if(s[i] == 'R') red++;
		else blue++;
	}
	if(red>blue) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
		
}







