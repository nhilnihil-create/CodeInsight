#include <bits/stdc++.h>
using namespace std;

int main(){
  using idx= tuple<int, int, int>;
  using state= pair<int64_t, idx>;
  int N1,N2,N3,K;
  cin >> N1 >> N2 >> N3 >> K;

  vector<int64_t> cake1(N1);
  vector<int64_t> cake2(N2);
  vector<int64_t> cake3(N3);

  for(int i=0; i<N1; i++){
    cin >> cake1.at(i);
  }
  for(int i=0; i<N2; i++){
    cin >> cake2.at(i);
  }
  for(int i=0; i<N3; i++){
    cin >> cake3.at(i);
  }
  
  sort(cake1.begin(), cake1.end(), greater<int64_t>());
  sort(cake2.begin(), cake2.end(), greater<int64_t>());
  sort(cake3.begin(), cake3.end(), greater<int64_t>());

  priority_queue<state> outputs;
  set<idx> pushed_idx;
  outputs.push(make_pair(cake1.at(0)+ cake2.at(0)+ cake3.at(0), make_tuple(0,0,0)));
  pushed_idx.insert(make_tuple(0,0,0));

  int cnt= 0;
  int64_t val; idx idx_this; int id1,id2,id3;
  while(cnt < K){
    state output= outputs.top();
    outputs.pop();

    tie(val, idx_this)= output;
    tie(id1, id2, id3)= idx_this;
    cout << val << endl;

    idx next1= make_tuple(id1+1, id2  , id3);
    idx next2= make_tuple(id1  , id2+1, id3);
    idx next3= make_tuple(id1  , id2  , id3+1);

    if(get<0>(next1) < N1 && !pushed_idx.count(next1)){
      outputs.push(make_pair(cake1.at(get<0>(next1))+ cake2.at(get<1>(next1))+ cake3.at(get<2>(next1)), next1));
      pushed_idx.insert(next1);
    }
    if(get<1>(next2) < N2 && !pushed_idx.count(next2)){
      outputs.push(make_pair(cake1.at(get<0>(next2))+ cake2.at(get<1>(next2))+ cake3.at(get<2>(next2)), next2));
      pushed_idx.insert(next2); }
    if(get<2>(next3) < N3 && !pushed_idx.count(next3)){
      outputs.push(make_pair(cake1.at(get<0>(next3))+ cake2.at(get<1>(next3))+ cake3.at(get<2>(next3)), next3));
      pushed_idx.insert(next3);
    }

    cnt++;
  }
}