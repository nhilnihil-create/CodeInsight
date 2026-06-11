#include <bits/stdc++.h>
using namespace std;



int main() {
  int N;
  cin>>N;
  vector<tuple<string, int, int>> vec;
  for(int i=0;i<N;i++){
    string s;
    int a;
    cin>>s>>a;
    vec.push_back(make_tuple(s,-a,i+1));
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<N;i++){
    cout << get<2>(vec.at(i)) << endl;
  }
  
    
}