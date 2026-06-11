#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  
  vector<tuple<string,int,int>> pa(N);
  
  for(int i=0; i<N; i++){
    string s;
    int p,j=i+1;
    cin >> s >> p;
    pa.at(i) = make_tuple(s,-p,j);
  }
  
  sort(pa.begin(),pa.end());

  for(int i=0; i<N; i++){
    string s;
    int p,j;
    tie(s,p,j) = pa.at(i);
    cout << j << endl;
  }
  
}
