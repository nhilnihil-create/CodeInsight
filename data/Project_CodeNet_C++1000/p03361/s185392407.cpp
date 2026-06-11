#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using vc2 = vector<vector<char>>;
int H;
int W;
v1 mh = {-1, 0, 0, 1};
v1 mw = {0, -1, 1, 0};

void paint(vc2& s, int h, int w){
	if(s.at(h).at(w) == '.') return;
	rep(i, 4){
		int nh = h + mh.at(i);
		int nw = w + mw.at(i);
		if(nh >= H || nw >= W || nh <0 || nw<0) continue;
		if(s.at(nh).at(nw) == '#'){
			s.at(h).at(w) = 'b';
			s.at(nh).at(nw) = 'b';
		}
	}
}


int main(){
	cin >> H >> W;
	vc2 s(H,vector<char>(W));
	rep(i, H){
		rep(j, W){
			cin >> s.at(i).at(j);
		}
	}
	rep(i, H){
		rep(j, W){
			paint(s, i, j);
		}
	}
	rep(i, H){
		rep(j, W){
			if(s.at(i).at(j)== '#'){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
