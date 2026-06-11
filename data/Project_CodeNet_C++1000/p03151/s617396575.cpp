#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

int a[100005];
int b[100005];

int32_t main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	vector<int> pool;
	int need = 0;
	int change = 0;
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]){
			pool.push_back(a[i]-b[i]);
		}
		else {
			change += (a[i]!=b[i]);
			need += (b[i]-a[i]);
		}
	}
	sort(all(pool),greater<int>());
	for(auto x:pool){
		if(!need){
			break;
		}
		need = max(0LL,need-x);
		change++;
	}
	if(need){
		cout<<-1;
		return 0;
	}
	cout<<change;
}
