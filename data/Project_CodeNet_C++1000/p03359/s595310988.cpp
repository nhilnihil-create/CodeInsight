#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
const int INF=1001001001;

int main(){
	int a,b;
	cin >> a >> b;
	int ans = a-1;
	if(a<=b) ans = a;
	cout << ans << endl;

	return 0;

}


