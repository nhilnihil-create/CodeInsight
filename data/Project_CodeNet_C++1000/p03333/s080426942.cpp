#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

const int Nmax=200010;

int main() {
	ll N;
	cin >> N;
	vector<int> L(N),R(N);
	for(int i=0;i < N;i++){
		cin >> L[i] >> R[i];
	}
	sort(L.begin(), L.end());
	reverse(L.begin(), L.end());
	sort(R.begin(), R.end());
	ll ans1=0,ans2=0;
	ll now=0;//現在の座標　nowより内側へ内側へと行く
	for(int i=0;i < N;i++){
		if(now < L[i]){//最初に右行くver
			ans1+=abs(L[i]-now);
			now = L[i];
		}else break;
		if(now > R[i]){
			ans1+=abs(now-R[i]);
			now = R[i];
		}else break;
	}
	ans1+=abs(now);
	
	now = 0;
	for(int i=0;i < N;i++){
		if(R[i] < now){//最初に左行くver
			ans2+=abs(now-R[i]);
			now = R[i];
		}else break;
		if(L[i] > now){
			ans2+=abs(L[i]-now);
			now = L[i];
		}else break;
	}
	ans2+=abs(now);
	cout << max(ans1, ans2) << endl;
	return 0;
}