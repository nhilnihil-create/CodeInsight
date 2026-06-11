#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> fav(M);
	rep(i,N){
		int K;cin >> K;
		rep(j,K){
			int tmp;
			cin >> tmp;
			fav[tmp-1]++;
		}
	}
	int ans = 0;

	rep(i,M){
		if(fav[i] == N) ans++;
	}
	cout << ans << endl;
}











