#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

struct train{
	ll c,s,f;
};

int main(){
	int n;
	cin >> n;
	vector<train> t(n-1);
	rep(i,n-1){
		cin >> t[i].c >> t[i].s >> t[i].f;
	}
	rep(i,n-1){
		ll time = 0;
		//駅iから出発する。
		for (int j = i; j < n-1; ++j) {
			if(time < t[j].s){
				time += t[j].c + t[j].s - time;
			}else{
				if(time % t[j].f == 0){
					time += t[j].c;
				}else{
					time += t[j].f - (time % t[j].f) + t[j].c;
				}
			}
		}
		cout << time << endl;
	}
	cout << 0 << endl;
    return 0;
}

