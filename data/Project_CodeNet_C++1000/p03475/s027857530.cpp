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
	ll N;
	cin >> N;

	vector<ll> C(N-1), S(N-1), F(N-1);
	for(int i=0; i<N-1; i++) cin >> C[i] >> S[i] >> F[i];
	S.push_back(0);

	for(int i=0; i<N; i++){
		ll time = 0;
		for(int now=i; now<N-1; now++){
			ll num = max(time-S[now], (ll)0);
			ll start_time = S[now] + (num + F[now] - 1)/F[now]*F[now];
			// cout << "  i: " << i << " now: " << now << "  time: " << time << "  F[now]: " << F[now] << " time/S[now]*F[now]: " << time/S[now]*F[now] << "  S[now]: " << S[now] <<  "   start_time : " <<  start_time << "    C[now]: " << C[now] <<endl;
			time = start_time + C[now];
			
		}
		cout << time << endl;
		// cout << "  ------------------" << endl;
	}
	

	return 0;
}

