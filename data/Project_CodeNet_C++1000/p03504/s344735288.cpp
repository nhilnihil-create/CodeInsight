#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, c;
	cin >> n >> c;
	vector<vector<int>> t(30, vector<int>(0));
	rep(i, n){
		int si, ti, ci;
		cin >> si >> ti >> ci;
		ci--;
		t.at(ci).push_back(si);
		t.at(ci).push_back(ti);
	}
	rep(i, 30) sort(t.at(i).begin(), t.at(i).end());
	vector<vector<int>> t0(30, vector<int>(0));
	rep(i, 30){
		int k = t.at(i).size();
		rep(j, k){
			if(j == 0){
				t0.at(i).push_back(t.at(i).at(0));
			}else if(j == k-1){
				t0.at(i).push_back(t.at(i).at(k-1));
			}else{
				if(k > 0 && t.at(i).at(j) != t.at(i).at(j+(j%2*2-1))) t0.at(i).push_back(t.at(i).at(j));
			}
		}
	}
	vector<vector<int>> t1(30, vector<int>(0));
	rep(i, 30){
		rep(j, t0.at(i).size()) t1.at(i).push_back(t0.at(i).at(j)*2-1*((j+1)%2));
	}
	vector<int> sum(200002);
	rep(i, 30){
		int sig = 0;
		int k = t1.at(i).size();
		rep(j, k){
			if(j%2 == 0){
				sum.at(t1.at(i).at(j))++;
			}else{
				sum.at(t1.at(i).at(j))--;
			}
		}
	}
	int sig = 0;
	int ma = 0;
	rep(i, 200002){
		sig += sum.at(i);
		if(sig > ma) ma = sig;
	}
	cout << ma << endl;
	return 0;
}