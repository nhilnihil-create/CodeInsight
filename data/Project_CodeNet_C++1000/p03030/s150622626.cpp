#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<pair<pair<string,int>,int>> X(N);
  for(int i=0; i<N; i++){
    string s;
    int p;
    cin >> s ;
    cin >> p;
    X[i] = make_pair(make_pair(s,-p),i);//点数は高い順で並べたいので負の符号をつけておく
  }
  
  sort(X.begin(), X.end());
  
  for(int i=0; i<N; i++){
    cout << X[i].second+1 << endl;
  }
  
  
}

