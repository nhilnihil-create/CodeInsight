#include <bits/stdc++.h>
using namespace std;


int main() {

  int n,m;
  cin>>n>>m;

  vector<tuple<int, int, int, int >> tuples(m);
  for(int i=0;i<m;i++){
    int p,y;
    cin>>p>>y;
    tuples.at(i) = make_tuple(p,y,i,0);
  }

  sort(tuples.begin(),tuples.end());

  int previous=get<0>(tuples.at(0));
  get<3>(tuples.at(0))=1;
  int cnt=1;
  for(int i=1;i<m;i++){
    if(get<0>(tuples.at(i))==previous){
      cnt++;
      get<3>(tuples.at(i))=cnt;
    }else{
      cnt=1;
      get<3>(tuples.at(i))=cnt;
      previous=get<0>(tuples.at(i));
    }
  }

  for(int i=0;i<m;i++){
    int wk = get<0>(tuples.at(i));
    get<0>(tuples.at(i))=get<2>(tuples.at(i));
    get<2>(tuples.at(i))=wk;
  }

  sort(tuples.begin(),tuples.end());

  for(int i=0;i<m;i++){
    cout<<setfill('0')<<right<<setw(6)<<get<2>(tuples.at(i))<<setfill('0')<<right<<setw(6)<<get<3>(tuples.at(i))<<endl;
  }

  return 0;
}


