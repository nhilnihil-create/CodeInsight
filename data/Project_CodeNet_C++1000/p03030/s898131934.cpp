#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  using vppsii=vector<pair<pair<string,int>,int>>;
  vppsii a(N);
  for(int i=0;i<N;i++){
    string s;
    int p;
    cin>>s>>p;
    a.at(i)=make_pair(make_pair(s,-p),i+1);
  }
  sort(a.begin(),a.end());
  for(auto e:a){
    cout<<e.second<<endl;
  }
}