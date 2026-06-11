#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, M, C;
	cin >> N >> M >> C;
	vector<int> B(M);
	rep(i,M) cin >> B[i];
	int ans = 0;
	rep(i,N){
		int tmp = 0;
		rep(j,M){
			int a;cin >> a;
			tmp += a * B[j];
		}
		if(tmp + C > 0) ans++;
	}
	cout << ans << endl;
}











