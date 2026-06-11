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

using P = pair<char, int>;
int main(){
	string S, T;
	cin >> S >> T;

	int N = S.size();
	bool is_can = true;
	vector<vector<int>> s_vec(26, vector<int>());	
	for(int i=0; i<N; i++) s_vec[S[i]-'a'].push_back(i);
	for(int i=0; i<26; i++){
		for(int j=1; j<s_vec[i].size(); j++){
			int place1 = s_vec[i][j-1];
			int place2 = s_vec[i][j];
			if(T[place1] != T[place2]) is_can = false;
		}
	}

    vector<vector<int>> t_vec(26, vector<int>());
	for(int i=0; i<N; i++) t_vec[T[i]-'a'].push_back(i);
	for(int i=0; i<26; i++){
		for(int j=1; j<t_vec[i].size(); j++){
			int place1 = t_vec[i][j-1];
			int place2 = t_vec[i][j];
			if(S[place1] != S[place2]) is_can = false;
		}
	}
	// cout << " S: " << S  << "     T: " << T << endl;
	// cout << " t_vec: "; print_vec2(t_vec);

	// vector<P> vec;
	// for(int i=0; i<N; i++){
	// 	if(S[i] == T[i]){
	// 		vec.emplace_back(P(S[i], i));
	// 	}
	// }

	// bool is_can = true;
	// for(int i=0; i<(int)vec.size(); i++){
	// 	char c = vec[i].first;
	// 	int place = vec[i].second;
	// 	for(int j=0; j<N; j++){
	// 		if(j!=place && T[j] == c) is_can = false;
	// 	}
	// }

	if(is_can) cout << "Yes" << endl;
	else cout << "No" << endl; 


}

