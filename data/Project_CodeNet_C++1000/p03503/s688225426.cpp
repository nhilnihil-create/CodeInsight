#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, int num=0){
  if(num == 0) num = (int)v.size();
  if(is_reverse) for(int i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<" ";}
  else for(int i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<" ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, int num=0){
  if(num == 0) num = (int)v.size();
  cout << endl;
  for(int i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
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

int main(){
	int N;
	cin >> N;
	const int DAYS = 10;
	vector<vector<int>> F(N, vector<int>(DAYS));
	for(int i=0; i<N; i++){
		for(int j=0; j<DAYS; j++) cin >> F[i][j];
	}

	vector<vector<ll>> P(N, vector<ll>(DAYS+1));
	for(int i=0; i<N; i++){
		for(int j=0; j<DAYS+1; j++) cin >> P[i][j];
	}


	//bit全探索
	const ll INF = 10e18;
	ll ans = -INF;
	for(int i=0; i<(1<<DAYS); i++){ 
		bitset<10> bit(i);		//開ける日を1とする
		if(bit.count() == 0) continue;// 店は一回以上開かないといけない
		
		vector<int> num(N, 0);// num[i]: 店iと 自分の店が営業する日数
		for(int j=0; j<DAYS; j++){			
			if(bit[j]){  	// 自分の店を開けるなら
				for(int shop=0; shop<N; shop++){
					if(F[shop][j]) num[shop]++;
				}
			}
		}
		// cout << "  num: "; print_vec(num);
		ll yen = 0;
		for(int shop=0; shop<N; shop++){
			yen += P[shop][num[shop]];
		}
		
		ans = max(ans, yen);
	}
	

	cout << ans << endl;
	
}

