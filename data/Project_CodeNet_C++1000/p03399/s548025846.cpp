#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
const int INF=1001001001;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int ans=0;
	if(a<b){
		ans += a;
	}else ans += b;
	if(c<d){
		ans += c;
	}else ans += d;
	cout << ans << endl;

	return 0;

}


