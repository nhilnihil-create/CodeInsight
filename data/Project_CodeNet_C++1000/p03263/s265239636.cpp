#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int h, w;
	cin >> h >> w;
	int a[500][500];
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> a[i][j];
		}
	}
	vector<pair<pair<int, int>, pair<int, int> > > ans;
	for (int i = 0; i < h; i++){
		if (i%2 == 0){
			for (int j = 0; j < w; j++){
				if (j == w-1){
					if (a[i][j]%2 && i != h-1){
						ans.push_back(make_pair(make_pair(i, j), make_pair(i+1, j)));
						a[i+1][j]++;
					}
				}else{
					if (a[i][j]%2){
						ans.push_back(make_pair(make_pair(i, j), make_pair(i, j+1)));
						a[i][j+1]++;
					}
				}
			}
		}else{
			for (int j = w-1; j >= 0; j--){
				if (j == 0){
					if (a[i][j]%2 && i != h-1){
						ans.push_back(make_pair(make_pair(i, j), make_pair(i+1, j)));
						a[i+1][j]++;
					}
				}else{
					if (a[i][j]%2){
						ans.push_back(make_pair(make_pair(i, j), make_pair(i, j-1)));
						a[i][j-1]++;
					}
				}
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].first.first+1 << " " << ans[i].first.second+1 << " ";
		cout << ans[i].second.first+1 << " " << ans[i].second.second+1 << endl;
	}
	return 0;
}