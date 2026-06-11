#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,tmp;
  vector<int> d;
  map<int,int> M;

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> tmp;
    d.push_back(tmp);
  }

  for(int i=0;i<N;i++){
    if(M.count(d.at(i))>0)
      M.at(d.at(i))++;
    else
      M[d.at(i)] = 1;
  }

  cout << M.size() << endl;

}
