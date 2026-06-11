#include <bits/stdc++.h>
using namespace std;

int main() {
	long n,m,i,j,ans,cur;
	cin >> n;
	vector<long> a(n);
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	vector<long> s(0);
	
	s.push_back(0);
	cur=0;
	for(i=0; i<n; i++){
		cur+=a[i];
		s.push_back(cur);
	}
	sort(s.begin(), s.end());
	j=0; ans=0;
	for(i=1; i<=n; i++){
		if(s[j]==s[i]){
			ans+=i-j;
		}else{
			j=i;
		}
	}
	cout << ans << endl;
	return 0;
}
