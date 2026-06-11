#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	int cnt=0;
	for(int i=0;i<=3000;i++){
		for(int j=0;j<=3000;j++){
			int a = n-i*r-j*g;
			if(a%b==0&&a>=0) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
