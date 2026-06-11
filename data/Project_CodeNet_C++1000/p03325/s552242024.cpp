#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N; cin >> N;
	LL ans = 0;
	rep(i,N) {
		LL tmp;cin >> tmp;
		while(tmp%2==0){
			ans++;
			tmp /= 2;
		}
	}
	cout << ans << endl;

}












