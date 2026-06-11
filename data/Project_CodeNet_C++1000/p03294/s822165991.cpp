#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(){
	int n; cin>>n;
	int sum = 0;
	int val;
	for(int i=0; i<n; i++){
		cin>>val;
		sum+=val;
	}
	cout<<sum-n;
}

int main(){
	fast;
	solve();
}