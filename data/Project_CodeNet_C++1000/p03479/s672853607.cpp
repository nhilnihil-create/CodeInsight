#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;

int main() {
	ll x,y;
	cin>>x>>y;
	int ans=0;
	while(x<=y){
		x*=2;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}