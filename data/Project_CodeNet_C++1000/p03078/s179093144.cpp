#include <bits/stdc++.h>
using namespace std;

int main(){
  using state= pair<int64_t, int>;
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
  
  vector<int64_t> cake12;
  for(auto c1:cake1){
    for(auto c2:cake2){
      cake12.emplace_back(c1+ c2);
    }
  }

  sort(cake12.begin(), cake12.end(), greater<int64_t>());
  sort(cake3.begin(), cake3.end(), greater<int64_t>());

  priority_queue<state> outputs;
  vector<int> id12_push(N3, -1);
  vector<int> id12_output(N3, -1);
  outputs.push(make_pair(cake12.at(0)+ cake3.at(0), 0));
  id12_push.at(0)= 0;

  int cnt= 0;
  int64_t val; int id3_this;
  while(cnt < K){
    state output= outputs.top();
    outputs.pop();

    tie(val, id3_this)= output;
    cout << val << endl;

    id12_output.at(id3_this)++;
    int id12_output_this= id12_output.at(id3_this);

    if(id3_this+ 1 < N3){
      int id3_ngh= id3_this+ 1;
      int id12_output_ngh = id12_output.at(id3_ngh);

      if(id12_output_ngh==id12_output_this- 1){
        id12_push.at(id3_ngh)++;
        int id12_push_ngh = id12_push.at(id3_ngh);

        outputs.push(make_pair(cake12.at(id12_push_ngh)+ cake3.at(id3_ngh), id3_ngh));
      }
    }
    if(id12_output_this+ 1 < N1*N2){
      int id3_ngh= id3_this- 1;
      int id12_output_ngh= (id3_this > 0) ? id12_output.at(id3_ngh)
                                          : -1;

      if(id3_this==0 || id12_output_ngh > id12_output_this){
        id12_push.at(id3_this)++;
        int id12_push_this= id12_push.at(id3_this);

        outputs.push(make_pair(cake12.at(id12_push_this)+ cake3.at(id3_this), id3_this));
      }
    }

    cnt++;
  }
}