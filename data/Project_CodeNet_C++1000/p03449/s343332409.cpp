#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<vector<int>> vv(2,vector<int>(n));
	rep(i,2){
		rep(j,n){
			cin>>vv[i][j];
		}
	}
	int mx=0;
	int cnt1=0;
	rep(i,n){
		cnt1+=vv[0][i];
		int cnt2=0;
		for(int j=i; j<n; j++){
			cnt2+=vv[1][j];
		}
		mx=max(mx,cnt1+cnt2);
	}
	cout<<mx<<endl;
}