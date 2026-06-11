#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; cout << "i=  ";for(ll i=0; i<num; i++) cout << i << "   ";cout << endl;  
  cout << "    ";
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<"   ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<"   ";}
  cout << endl;
}

// template <typename T>
// void print_pairvec(const vector<T> &v, ll num=0){
//   if(num == 0) num = (ll)v.size();
//   cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
// }
template <typename T>
void print_pairvec(const T &_pair, ll num=0){
  cout << endl; for(pair<ll, int> x: _pair){ cout << x.first << " " << x.second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

// GCD, LCM
// https://youtu.be/8lm8o8L9Bmw?t=2285
// https://youtu.be/XI8exXVxZ-Q?t=3595
// https://youtu.be/F2p_e6iKxnk?t=843
// ll GCD(ll a, ll b) { return b?GCD(b,a%b):a;}
// ll LCM(ll a, ll b) { return a/GCD(a,b)*b;}

ll GCD(ll a, ll b){
  if(b == 0) return a;
  return GCD(b, a%b);//オーバーフローしないように先にgcd(a, b)で割る
}
ll LCM(ll a, ll b){return a/GCD(a, b)*b;}

int main(){
  ll N, X;
  cin >> N >> X;
  vector<ll> x(N);
  for(int i=0; i<N; i++) cin >> x[i];

  x.push_back(X);
  sort(x.begin(), x.end());
  vector<ll> interval(N);
  for(int i=1; i<(int)x.size(); i++) interval[i-1] = x[i] - x[i-1];
  // cout << " x: "; print_vec(x);
  // cout << " interval: "; print_vec(interval);
  ll gcd = 0;
  for(int i=0; i<(int)interval.size(); i++) gcd = GCD(gcd, interval[i]);
  cout << gcd << endl; 

  return 0;
  // cout << fixed;//小数点を確実に10桁で表示するためのもの
  // cout << setprecision(10); 
}
