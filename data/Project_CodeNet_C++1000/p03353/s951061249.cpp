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
	string  S;
	int K;
	cin >> S >> K;

	// vector<string> tmp;
	// tmp.push_back("aaa");
	// tmp.push_back("a");
	// tmp.push_back("b");
	// tmp.push_back("bbb");
	// sort(tmp.begin(), tmp.end());
	// for(int i=0; i<(int)tmp.size(); i++) cout << tmp[i] << endl;

	vector<string> subs;
	int N = S.size();
	for(int i=1; i<=5; i++){
		for(int j=0; j<N+1-i; j++){
			subs.push_back(S.substr(j,i));
		}
	}
	
	sort(subs.begin(), subs.end());
	// cout << "  subs: "; print_vec(subs);
	// cout << subs[K-1] << endl;

	map<string, int> mp;
	for(string s: subs){
		if(mp[s] != 0) mp[s]++;
		if(mp.size() == K){
			cout << s << endl;
			return 0;
		}
	}
	return 0;
}

