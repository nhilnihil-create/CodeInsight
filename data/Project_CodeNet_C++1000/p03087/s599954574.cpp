#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
        
int main(){
	int n,q; cin >> n >> q;
	string s; cin >>s;
	vector<int> ans(n+1,0);

	for(int i=0;i<n;i++){
		if(i+1 < n && s[i]=='A' && s[i+1]=='C') ans[i+1]=ans[i]+1;
		else ans[i+1]=ans[i];
	}


	for(int p=0;p<q;p++){
		int l,r;cin >> l >> r;
		--r;
		--l;
		cout << ans[r] - ans[l] << endl;
	}
}
