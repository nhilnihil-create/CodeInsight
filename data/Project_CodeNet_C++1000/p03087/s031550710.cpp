#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, Q;

int main(){
	cin >> N >> Q;
	string S;
	cin >> S;
	int len = S.size();
	
	vector<int> acc(len); // acc[i] : 0..i の間にACがいくつあるか
	acc[0] = 0;
	
	int ct = 0;
	for ( int i = 1; i < len; i++ ){
		if ( S[i-1] == 'A' && S[i] == 'C' )
			ct++;
		acc[i] = ct;
	}
	
	
	for ( int i = 0; i < Q; i++ ){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		
		cout << acc[r]-acc[l] << endl;
	}
	
	return 0;
}

