#include<bits/stdc++.h>
using namespace std;

const int INF = 1 << 12;

int main(){
  int N ;
  cin >> N ;
  
  pair<pair<string,int>,int> p[110];
  for(int i = 0; i < N; i++){
    int a; string s;
    cin >> s >> a;
    p[i] = make_pair(make_pair(s, -a),i);
  }
  
  sort(p,p + N);
  for(int i = 0; i < N; i++) cout << p[i].second + 1 << endl;
  
  
}