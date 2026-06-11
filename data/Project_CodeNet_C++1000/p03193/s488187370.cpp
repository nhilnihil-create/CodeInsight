#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	ll n,h,w;
	cin >> n >> h >> w;
	int ans = 0;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		if(a>=h && b>=w){
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
