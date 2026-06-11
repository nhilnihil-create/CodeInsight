#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair< int, int > ii;
typedef vector< ii > vii;

void solve(){
	int n, m, c; cin>>n>>m>>c;
	vector< int > b(m);
	for(int &i : b) cin>>i;

	int a[n][m], cnt = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>a[i][j];
		}
		int ans = c;
		for(int j = 0; j<m; j++){
			ans += a[i][j] * b[j];
		}
		if(ans > 0){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

