#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;

int a,b;

bool check(int p){
	int mid = (p+1)/2;
	
	ll mx=0;
	for(int i=mid-10;i<=mid+10;i++){
		if(i<=0 || i>p+1 || i==a)
			continue;
		
		int below = i-(i>=a);
		int j=p+1+(p>=b)-below;
		j-=(j<=b && p>=b);
		
		if(j<=0 || j>p+1 || j==b)
			continue;
		mx=max(mx,1ll*i*j);
	}
	return mx<1ll*a*b;
}

void test_case(){
	cin >> a >> b;
	if(a>b)
		swap(a,b);
	
	int l=0, r=2e9+5;
	while(l+1<r){
		int mid = (1ll*l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout << l << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tcase; cin >> tcase;
	while(tcase--){
		test_case();
	}
	
	return 0;
}