#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int sum=0;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin>>a[i], sum+=a[i];
	int ret=-1, best=INT_MAX;
	for (int i=0; i<n; i++) {
		int cur=abs(a[i]*n-sum);
		if(best>cur) best=cur, ret=i;
	}
	cout<<ret<<"\n";
	return 0;
}