#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	string C[2];
	cin >> C[0] >> C[1];
	reverse(C[0].begin(),C[0].end());
	if(C[0]==C[1]) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}