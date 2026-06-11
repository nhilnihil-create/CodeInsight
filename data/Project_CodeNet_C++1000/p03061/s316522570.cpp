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

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A[i];
  vector<int> left(N), right(N);
  left[0] = 0;// left[i]: 左端からi-1番目までのGCD (i番目は含まない)
  for(int i=1; i<N; i++){
    left[i] = gcd(left[i-1], A[i-1]);
  }
  right[N-1] = 0;//right[i]: 右端からi-1番目までのGCD (i番目は含まない)
  for(int i=1; i<N; i++){
    right[N-i-1] = gcd(right[N-i], A[N-i]);
  }

  int ans = 0;
  for(int i=0; i<=N; i++){ //A[i]を含まない数列Aのgcdを計算していく
    ans = max(ans, gcd(left[i], right[i]));
  }
  cout << ans << endl;
  return 0;
}
