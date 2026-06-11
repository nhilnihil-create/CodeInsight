#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

float calc(float seg1, float seg2, float v, float time, float end) {
	float res = time;
	res = min(res, end-time);
	if (seg1 <= time && time <= seg2){
		res = min(res, v);
	} else if (seg1 > time) {
		res = min(res, v + (seg1-time));
	} else {
		res = min(res, v + (time-seg2));
	}
	//res = max(res, (float) 0);
	return res;
}

int main() {
	int n; cin >> n;
	vector<int> t(n);
	int total = 0;
	vector<pair<int, int> > time_cum(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		time_cum[i] = make_pair(total, total+t[i]);
		total += t[i];
	}
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	vector<float> maxspeed(2*total+1, (float) 1000);
	for (float i = 0; i <= total; i += 0.5)
	{
		int j = (int) (i*2);
		for (int k = 0; k < n; ++k)
		{
			float res = calc((float) time_cum[k].first, (float) time_cum[k].second, (float) v[k], i, (float) total);
			maxspeed[j] = min(maxspeed[j], res);
		}
		//cout << maxspeed[j] << endl;
	}

	float ans = 0;
	for (int i = 0; i < 2*total; ++i)
	{
		ans += (maxspeed[i] + maxspeed[i+1]) / 4.0;
	}
	cout << std::setprecision(12) << ans << endl;
	return 0;
}