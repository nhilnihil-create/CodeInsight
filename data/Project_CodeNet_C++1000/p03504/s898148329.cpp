#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, C;
  cin >> N >> C;
  vector<vector<int>> vec(N,vector<int>(3));
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      cin >> vec.at(i).at(j);
    }
  }
  sort(vec.begin(),vec.end());
  pair<int,int> P;
  vector<pair<int,int>> R(0);
  for(int i=0; i<N; i++){
    int a = vec.at(i).at(0);
    int b = vec.at(i).at(1);
    int c = vec.at(i).at(2);
    bool flag = false;
    int end = 1000000000;
    int tv = -1;
    for(int j=0; j<R.size(); j++){
      if(end > R.at(j).first){
        if(a > R.at(j).first || (a == R.at(j).first && c == R.at(j).second)){
          end = R.at(j).first;
          tv = j;
          flag = true;
        }
      }
    }
    if(!flag){
      P = make_pair(b,c);
      R.push_back(P);
    }
    else{
      P = make_pair(b,c);
      R.at(tv) = P;
    }
  }
  cout << R.size() << endl;
}