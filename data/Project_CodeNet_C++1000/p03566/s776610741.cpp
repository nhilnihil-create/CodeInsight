#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	double t[200], v[200];
	for (int i = 0;i < N;i++){
		cin >> t[i];
	}
	for (int i = 0;i < N;i++){
		cin >> v[i];
	}

	double sum[200];

	sum[0] = 0;
	for (int i = 1;i <= N;i++){
		sum[i] = sum[i-1]+t[i-1];
	}
	v[N] = 0;

	double dist = 0;
	double speed = 0;
	int idx = 0;

	double d = 0.25;

	for (double time = 0;time < sum[N];time += d){
		if(time >= sum[idx+1]) idx++;
		bool can_keep = true;
		for (int j = idx+1;j <= N;j++){
			if(speed-v[j] > sum[j]-(time+d)){ can_keep = false; break;}
		}
		if(!can_keep){ dist += speed*d - (d*d)/2; speed -= d; continue;}
		bool can_acc = true;
		if(speed+d > v[idx]){ dist += speed*d; continue;}
		for (int j = idx+1;j <= N;j++){
			if(speed+d-v[j] > sum[j]-(time+d)){ can_acc = false; break;}
		}
		if(!can_acc){dist += speed; continue;}
		dist += speed*d+(d*d)/2; speed += d;
	}

	printf("%.10f\n", dist);

	return 0;

}
