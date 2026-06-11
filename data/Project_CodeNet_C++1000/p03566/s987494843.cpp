#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> t(N),v(N);
	int T = 0;
	rep(i,N){
		cin >> t[i];
		T += t[i];
	}
	rep(i,N)cin >> v[i];
	vector<double> maxv(T*2+5,(double)1e9);//maxv[i] := 時刻i/2 での出せる最高速度
	int cur = 1;
	for(int i=0;i<N;i++){//各v[i]について
		for(int j=0;j<t[i]*2;j++){
			maxv[cur] = v[i];
			if(j==t[i]*2-1&&i+1<N)maxv[cur] = min((double)v[i+1],maxv[cur]);
			cur++;
		}
	}
	//for(int i=0;i<=2*T;i++)cout << "i= " << i << "のとき " <<  maxv[i] << endl;
	maxv[2*T] = 0;
	maxv[0] = 0;
	for(int i=1;i<=2*T;i++){
		maxv[i] = min(maxv[i],maxv[i-1] + (double)0.5);
	}
	
	for(int i=2*T-1;i>=0;i--){
		maxv[i] = min(maxv[i],maxv[i+1] + (double)0.5);
	}
	
	//for(int i=0;i<=2*T;i++)cout << "i= " << i << "のとき " <<  maxv[i] << endl;
	double ans = 0;
	for(int i=1;i<=2*T;i++){
		//高さ0.5
		//上底:maxv[i]
		//下底:maxv[i+1];
		ans += (maxv[i]+maxv[i-1])*0.5*0.5;
	}
	cout << fixed << setprecision(10) << ans << endl;
}