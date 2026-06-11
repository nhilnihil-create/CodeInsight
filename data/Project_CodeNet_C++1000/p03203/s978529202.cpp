#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int> > obstacleXtoY(200001);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		obstacleXtoY[x].push_back(y);
	}
	for(int i = 1; i <= h; i++){
		sort(obstacleXtoY[i].begin(), obstacleXtoY[i].end());
	}
	vector<pair<int, int> > nowRange;
	nowRange.push_back(make_pair(1, 2));
	for(int i = 2; i <= h; i++){
		// cout << i << endl;
		// nowRange : x = i - 1で、yとしてとりうる範囲
		// x = i - 1でゲームを終了できるかチェック
		int rangeItr = 0;
		for(int j = 0; j < obstacleXtoY[i].size(); j++){
			int obst = obstacleXtoY[i][j];
			while(rangeItr < nowRange.size() && obst > nowRange[rangeItr].second) rangeItr++;
			if(rangeItr == nowRange.size()) break;
			int l = nowRange[rangeItr].first;
			int r = nowRange[rangeItr].second;
			if(l <= obst && obst < r){
				cout << i - 1 << endl;
				return 0;
			}
		}
		// 次の行でのとりうる範囲を求める
		vector<pair<int, int> > nextRange;
		int itr = 0;
		for(int j = 0; j < nowRange.size(); j++){
			int l = nowRange[j].first;
			int r = nowRange[j].second;
			while(itr < obstacleXtoY[i].size() && obstacleXtoY[i][itr] < l) itr++;
			if(itr == obstacleXtoY[i].size()){
				nextRange.push_back(make_pair(l, r + 1));
				continue;
			}
			while(itr < obstacleXtoY[i].size() && obstacleXtoY[i][itr] <= r){
				if(l != obstacleXtoY[i][itr]){
					nextRange.push_back(make_pair(l, obstacleXtoY[i][itr]));
					l = obstacleXtoY[i][itr] + 1;
				}
				itr++;
			}
			if(l != r + 1){
				nextRange.push_back(make_pair(l, r + 1));
			}
		}
		nowRange.clear();
		for(int j = 0; j < nextRange.size(); j++){
			int l = nextRange[j].first;
			int r = nextRange[j].second;
			while(j + 1 < nextRange.size() && nextRange[j + 1].first < r){
				j++;
				r = nextRange[j].second;
			}
			nowRange.push_back(make_pair(l, r));
			// cout << l << " " << r << endl;
		}
	}
	cout << h << endl;
}