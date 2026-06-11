#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;

int main(){
  int n, m;
  cin >>n >> m;
  P p[100009];
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    p[i] = P(a, b);
  }
  sort(p, p+m);
  int cnt=1, r=p[0].second;
  for(int i=1;i<m;i++){
    if(p[i].first>=r){
      cnt++;
      r=p[i].second;
    }
    r=min(r, p[i].second);
  }
  cout << cnt << endl;
}

