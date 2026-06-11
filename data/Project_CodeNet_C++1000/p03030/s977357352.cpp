#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<tuple<string,int,int>> res;
  for(int i=0;i<N;i++){
    string S;
    int P;
    cin>>S>>P;
    res.push_back(make_tuple(S,100-P,i+1));
  }
  sort(res.begin(),res.end());
  for(tuple<string,int,int> t:res){
    cout<<get<2>(t)<<endl;
  }
}
