#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int> > a(h + 1, vector<int> (w + 1));
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> a[i][j];
		}
	}

	int cnt = 0;
	vector<tuple<int, int, int, int>> v;
	for(int i = 1; i <= h; i++){
		for(int j = 2; j <= w; j++){
			if(a[i][j - 1] %2 == 1){
				a[i][j - 1]--;
				a[i][j]++;
				v.push_back(make_tuple(i, j - 1, i, j));
				cnt++;
			}
		}
	}
	for(int i = 2; i <= h; i++){
		if(a[i-1][w]%2==1){
			a[i-1][w]--;
			a[i][w]++;
			v.push_back(make_tuple(i-1, w, i, w));
			cnt++;
		}
	}

	cout << cnt << endl;
	for(int i=0; i<v.size(); i++){
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << " " << get<3>(v[i]) << endl;
	}
	return 0;
}
