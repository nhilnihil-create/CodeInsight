#include <bits/stdc++.h>

using namespace std;
char t[200010],d[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int i,n,q;
	string s;
	cin >> n >> q >> s;
	for(i=0;i<q;i++){
		cin >> t[i] >> d[i];
	}
	int l = -1,r = n;
	for(i=q-1;i>=0;i--){
		if(d[i]=='L'){
			if(l<n-1 && s[l+1]==t[i]) l++;
			if(r<n && s[r]==t[i]) r++;
		}else{
			if(r>0 && s[r-1]==t[i]) r--;
			if(l>=0 && s[l]==t[i]) l--;
		}
	}
	cout << max(0,r - l - 1) << endl;
}