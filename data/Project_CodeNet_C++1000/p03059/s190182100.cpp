#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int a,b,t;
	cin >> a >> b >> t;
	int cnt=0;
	for(int i=1;i<t+1;i++){
		if(i%a==0) cnt+=b;
	}
	cout << cnt << endl;
	return 0;
}
