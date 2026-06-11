#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename TYPE>
void print_vec(const vector<TYPE>& v, int num=0){
  if(num == 0) num = (int)v.size();
	for(int i=0; i<num; i++){
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

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n=0): n(n), d(n+1){}

  void add(int i, T x=1){
    for(i++; i<=n; i+=i&(-i)){
      d[i] += x;
    }
  }
  
  T sum(int i){
    T x = 0;
    for(i++; i; i-=i&(-i)){
      x += d[i];
    } 
    return x;
  }
};

int main(){

  int INF = 100000;
  vector<int> num_divisor(INF+1, 0);
  for(int i=2; i<=INF; i++){
    if(num_divisor[i] > 1) continue;//これ入れるとエラトステネスの計算量O(Nlog(logN))になるかね
    for(int j=i; j<=INF; j+=i){
      num_divisor[j]++;
    }
  }

  //BITでも累積和でも解ける てか累積和のほうが知識レベル的に簡単だね
  // BIT<int> bi(INF+1);
  vector<int> wa(INF+1, 0);//累積和
  for(int i=2; i<=INF; i++){
    // if(num_divisor[i] == 1){
    //   if(num_divisor[(i+1)/2] == 1) bi.add(i);
    // }
    bool like_2017 = false;
    if(num_divisor[i] == 1){
      if(num_divisor[(i+1)/2] == 1) like_2017 = true;
    }
    wa[i] = wa[i-1] + like_2017;
  }
  int Q;
  cin >> Q;
  for(int i=0; i<Q; i++){
    int l, r;
    cin >> l >> r;
    // cout << bi.sum(r) - bi.sum(l-1) << endl;
    cout << wa[r] - wa[l-1] << endl;
  }

	return 0;
}

