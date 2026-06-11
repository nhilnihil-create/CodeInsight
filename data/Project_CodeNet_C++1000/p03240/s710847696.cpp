#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}


using P = pair<int ,int>;
using LPP = pair<ll, P>;
int main(){
	int N;
	cin >> N;
	vector<LPP> hxy(N);
	for(int i=0; i<N; i++){
		int x, y; ll h;
		cin >> x >> y >> h;
		hxy.emplace_back(h, P(x, y));
	}
	sort(hxy.rbegin(), hxy.rend());

	int ansx=-1, ansy=-1; ll ansH=-1;
	for(int Cx=0; Cx<=100; Cx++){
		for(int Cy=0; Cy<=100; Cy++){
			bool is_ok = true;
			ll h = hxy[0].first;
			int x = hxy[0].second.first;
			int y = hxy[0].second.second;
			ll H = h + abs(x-Cx) + abs(y-Cy);
			for(int i=1; i<N; i++){
				ll tmp = max(H - abs(hxy[i].second.first-Cx) - abs(hxy[i].second.second-Cy), (ll)0);
				// cout << " Cx: " << Cx << " Cy: " << Cy << " i: " << i << " H: " << H << " x: " << x << " y: " << y << " h: " << h << "  tmp: " << tmp << endl;
				if(hxy[i].first == tmp) continue; 
				is_ok = false;
				if(is_ok == false) break;
			}
			if(is_ok == true){
				ansH = H;
				ansx = Cx;
				ansy = Cy;
				break;
			}
		}
	}

	cout << ansx << " " << ansy << " "  << ansH << endl;


}

