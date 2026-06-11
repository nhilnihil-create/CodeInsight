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


using LP = pair<ll, int>;
string zeronumber(int x){
	string num = to_string(x);
	string zero = "";
	for(int i=6; i>(int)num.size(); i--) zero.push_back('0');
	return zero+num;
}
int main(){
	int N, M;
	cin >> N >> M;
	vector<LP> YP;
	for(int i=0; i<M; i++){
		int p; ll y;
		cin >> p >> y;
		p--;
		YP.emplace_back(y, p);
	}
	//sort(YP.begin(), YP.end());
	vector<vector<ll>> id(N, vector<ll>());//id[i][j]: 県iのj番目にできた年
	for(int i=0; i<M; i++){
		id[YP[i].second].push_back(YP[i].first);
	}
	// cout << " id: "; print_vec2(id);
	for(int i=0; i<N; i++){
		sort(id[i].begin(), id[i].end());
	}
	// cout << " id: "; print_vec2(id);
	for(int i=0; i<M; i++){
		int y = YP[i].first;
		int p = YP[i].second;
		string ue6 = zeronumber(p+1);
		
		auto iter = lower_bound(id[p].begin(), id[p].end(), y);
		auto index = iter - id[p].begin();
		string sita6 = zeronumber((int)index+1);
		cout << ue6 + sita6 << endl;
	}

	return 0;
}

