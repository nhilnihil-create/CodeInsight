#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  int N;
	cin>>N;
	vector<int> d(N);
	rep(i,N) cin>>d[i];
	sort(d.begin(),d.end());
	int ans=0;
	int r=0;
	rep(i,N){
		if (r!=d[i])ans+=1;
		r=d[i];
	}
	cout<<ans<<"\n";
}
