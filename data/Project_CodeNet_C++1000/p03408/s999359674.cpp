#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N;
  vector <string> b_str(N);
  for (int i = 0; i < N; ++i){
    cin >> b_str.at(i);
  }
  cin >> M;
  vector <string> r_str(M);
  vector <string> merge_str_vec(N + M);
  for (int i = 0; i < M; ++i){
    cin >> r_str.at(i);
  }
  for(int i = 0; i < N; ++i){
    merge_str_vec.at(i) = b_str.at(i);
  }
  for(int i = 0; i < M; ++i){
    merge_str_vec.at(N + i) = r_str.at(i);
  }
  sort(merge_str_vec.begin(), merge_str_vec.end());
  merge_str_vec.erase(unique(merge_str_vec.begin(), merge_str_vec.end()), merge_str_vec.end());
  vector<int> point(merge_str_vec.size());

  for(int i = 0; i < merge_str_vec.size(); ++i){
    for(int j = 0; j < N; ++j){
      if (merge_str_vec.at(i) == b_str.at(j)){
	++point.at(i);
      }
    }
    for(int j = 0; j < M; ++j){
      if (merge_str_vec.at(i) == r_str.at(j)){
	--point.at(i);
      }
    }
  }
  if(*max_element(point.begin(), point.end()) > 0)
    cout << *max_element(point.begin(), point.end()) << endl;
  else
    cout << 0 << endl;
}
