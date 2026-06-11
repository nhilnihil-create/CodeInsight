#include <bits/stdc++.h>
using namespace std;

int main() {
	long n,m,i,j,ans,cur;
	cin >> n;
	vector<string> s(n);
	for(i=0; i<n; i++){
		cin >> s[i];
	}
	
	ans=0;
	for(m=0; m<n; m++){
		cur=0;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(s[(m+i)%n][j]!=s[(m+j)%n][i]){
					cur=1;
				}
			}
		}
		if(cur==0){
			ans+=n;
		}
	}
	cout << ans;
	return 0;
}
