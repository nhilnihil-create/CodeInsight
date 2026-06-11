#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, M;
	cin >> N >> M;
	vector<P> S;
	rep(i,N){
		int A, B;
		cin >> A >> B;
		S.push_back(make_pair(A, B));
	}
	sort(S.begin(),S.end());
	LL ans = 0;
	rep(i,N){
		auto p = S[i];
		LL drink = p.first;
		LL num = p.second;
		if(M>num) {
			ans += drink * num;
			M -= num;
		}
		else {
		   	ans += drink * M;
			break;
		}
	}
	cout << ans << endl;
	return 0;

			

}












