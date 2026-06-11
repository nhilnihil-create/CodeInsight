#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<tuple<string,int,int>> Point(N);
  for(int i=0;i<N;i++){
    string s;
    int p;
    cin >> s >> p;
    Point[i]=make_tuple(s,100-p,i+1);
  }
  sort(Point.begin(),Point.end());
  for(int i=0;i<N;i++){
    cout << get<2>(Point[i]) << endl;
  }
}