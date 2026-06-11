#include<bits/stdc++.h>
const int N=2e5+10;
int a[N],n;
using namespace std;
typedef pair<int,int> pi;
set<pi> s;
int check(int lim){
	s.clear();
	s.insert(make_pair(-1,0));
	for (int i=1;i<=n;i++){
		if (a[i]>a[i-1])continue;
		while (s.size()&&s.rbegin()->first>a[i])s.erase(*s.rbegin());
		for (int j=a[i];j>=0;j--){
			if (j==0)return 0;
			if (s.rbegin()->first!=j){
				s.insert(make_pair(j,2));
				break;
			}
			int k=s.rbegin()->second;
			s.erase(*s.rbegin());
			if (k<lim){
				s.insert(make_pair(j,k+1));
				break;
			}
		}
	}
	return 1;
}
int main(){
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),ans|=a[i]<=a[i-1];
	if (!ans){
		cout<<1<<endl;
		return 0;
	}
	for (int u=1<<18;u;u>>=1){
		if (check(ans+u));
		else ans+=u;
	}
	cout<<ans+1<<endl;
}