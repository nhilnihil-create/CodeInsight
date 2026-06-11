#include<bits/stdc++.h>
 
using namespace std;

using ll = long long;

int main(){
	ll ans = 0;
	int N;cin >> N;
	int H,W;cin >> H >> W;
	for(int i = 0;i < N;i++){
		int X,Y;cin >> X >> Y;
		if(X >= H && Y >= W)ans++;
	}
	cout<<ans<<endl;
}