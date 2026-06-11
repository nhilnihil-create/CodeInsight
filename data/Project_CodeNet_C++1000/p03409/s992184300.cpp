#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int N;
typedef pair<int, int> point;
typedef tuple<int, point, vector<point>> redp;
vector<redp> redv;
vector<point> bluev;
map<point, int> bmap; //各青点が何個の赤点とペアになりうるかの個数

void delCandidate(point bp, vector<redp> &rpv){
	for(int i = 0; i < rpv.size(); i++){
		vector<point> &v = get<2>(rpv[i]);
		for(int j = 0; j < v.size(); j++){
			if(v[j] == bp){
				v.erase(v.begin() + j);
				get<0>(rpv[i]) -= 1;
				break;
			}
		}
		get<0>(rpv[i]) = v.size();
	}
	bmap[bp] = 0;
	for(int i=0; i<bluev.size(); i++){
		if(bluev[i] == bp){
			bluev.erase(bluev.begin() + i);
			break;
		}
	}
}

void calcbmap(){
	if(bmap.size() == 0) return;
	for(auto itr = bmap.begin(); itr != bmap.end(); itr++){
		point bp = itr->first;
		itr->second = 0;
		for(int i=0; i<redv.size(); i++){
			if(get<0>(redv[i]) == 0) continue;
			point rp = get<1>(redv[i]);
			vector<point> &v = get<2>(redv[i]);
			for(int j=0; j<v.size(); j++){
				if(bp == v[j]){
					bmap[bp]++;
				}
			}
		}
	}
}

void initRedPoints(){
	for(int i=0; i<redv.size(); i++){
		point rp = get<1>(redv[i]);
		vector<point> &v = get<2>(redv[i]);
		for(int j=0; j<bluev.size(); j++){
			point bp = bluev[j];
			if(bp.first > rp.first && bp.second > rp.second){
				v.push_back(bp);
			}
		}
		get<0>(redv[i]) = v.size(); 
	}
	calcbmap();
	int ezero = 1;
	while(ezero == 1){
		for(int i=0; i<redv.size(); i++){
			int cand = get<0>(redv[i]);
			if(cand == 0){
				redv.erase(redv.begin() + i);
				break;
			}
		}
		ezero = 0;
		for(int i=0; i<redv.size(); i++){
			int cand = get<0>(redv[i]);
			if(cand == 0){
				ezero = 1;
				break;
			}
		}
	}
}

// 候補の中の重複度が最小の青点候補を探す。
void searchBestBluePoint(vector<redp> &v, int &min_r, int &min_b, int &bx, int &by){
	int min_cand = 100;
	int ret = 0;
	for(int i=0; i<v.size(); i++){
		if(get<0>(v[i]) == 0) continue;
		vector<point> w = get<2>(v[i]);
		for(int j=0; j<w.size(); j++){
			if( min_cand > bmap[w[j]] ){
				min_cand = bmap[w[j]];
				bx = w[j].first;
				by = w[j].second;
				min_r = i;
				min_b = j;
				ret = 1;
			}
		}
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N ;
	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;
		vector<point> v;
		redv.push_back( make_tuple(0, make_pair(a, b), v) );
	}
	for(int i=0; i<N; i++){
		int c, d;
		cin >> c >> d;
		bluev.push_back( make_pair(c, d) );
		bmap[make_pair(c, d)] = 0;
	}

	initRedPoints();
	sort(redv.begin(), redv.end());
	int ans = 0;
	int count = 100;
	for(int i=0; i<redv.size(); i++){ count += get<0>(redv[i]); }
	while(count > 0 && redv.size() > 0){
		int min_r, min_b;
		int bx, by, ret;
		searchBestBluePoint(redv, min_r, min_b, bx, by);
		point candp = make_pair(bx, by);
		delCandidate(candp, redv);
		bmap[candp] = 0;
		ans++;
		redv.erase(redv.begin() + min_r);
		calcbmap();
		count = 0;
		for(int i=0; i<redv.size(); i++){ count += get<0>(redv[i]); }
	}
	printf("%d\n", ans);
	return 0;
}