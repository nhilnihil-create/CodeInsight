#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> T(M);
  int P, Y;
  for(int i=0; i<M; i++){
    cin >> P >> Y;
    T.at(i)=make_tuple(P, Y, i);
  }
  sort(T.begin(), T.end());
  int Now=1;
  for(int i=0; i<M; i++){
    if(i==0){
    }
    else if(get<0>(T.at(i))!=get<0>(T.at(i-1))){
      Now=1;
    }
    else{
      Now++;
    }
    get<1>(T.at(i))=Now;
  }   
  vector<pair<int, int>> K(M);
  for(int i=0; i<M; i++){
    K.at(get<2>(T.at(i)))=make_pair(get<0>(T.at(i)), get<1>(T.at(i)));
  }
  for(int i=0; i<M; i++){
    cout << setfill('0') << right << setw(6) << K.at(i).first;
    cout << setfill('0') << right << setw(6) << K.at(i).second << endl;
  }
}