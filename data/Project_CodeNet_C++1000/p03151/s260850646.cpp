#include <bits/stdc++.h>
using namespace std;
using univ= pair<int64_t, int64_t>;

int main(){
  int N;
  cin >> N;

  vector<univ> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i).first;
  }
  for(int i=0; i<N; i++){
    cin >> data.at(i).second;
  }

  auto comp= [](univ a, univ b){
    return a.second- a.first > b.second- b.first;
  };
  sort(data.begin(), data.end(), comp);

  int64_t shortage= 0;
  int cnt_short= 0;
  while(data.at(cnt_short).second- data.at(cnt_short).first > 0){
    shortage+= data.at(cnt_short).second- data.at(cnt_short).first;
    cnt_short++;
  }

  int cnt_surplus= 0;
  while(shortage > 0 && cnt_surplus < N){
    cnt_surplus++;
    int id_surplus= N- cnt_surplus;
    shortage-= data.at(id_surplus).first- data.at(id_surplus).second;
  }

  int ans= (shortage > 0) ? -1
                          : cnt_short+ cnt_surplus;

  cout << ans << endl;
}