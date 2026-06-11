#include<bits/stdc++.h>

using namespace std;

int main(void){
	int n, a, b;
	cin >> n >> a >> b;

	int cnt[3] = {0};
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if(p <= a){
			cnt[0]++;
		}
		if(a < p && p <= b){
			cnt[1]++;
		}
		if(b < p){
			cnt[2]++;
		}
	}

	cout << min(cnt[0], min(cnt[1], cnt[2])) << endl;


	return 0;
}
