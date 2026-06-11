#include<bits/stdc++.h>
using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
  int n;
  cin >> n;
  pair<int, int> p1[n], p2[n];
  int a,b;
  for ( int i = 0; i < n; i++){
    cin >> a >> b;
    p1[i] = make_pair(a, b);
  }
  for ( int i = 0; i < n; i++){
    cin >> a >> b;
    p2[i] = make_pair(a, b);
  }

  sort(p1, p1+n, compare_by_b);
  sort(p2, p2+n, compare_by_b);

  bool color[n];
  for ( int i = 0; i < n; i++)color[i] = false;

  int ans = 0;
  for ( int i = 0; i < n; i++){
    int max = -1, maxI = n;
    for ( int j = 0; j < n; j++){
      if ( p2[i].first > p1[j].first && p2[i].second > p1[j].second && !color[j] && max < p1[j].second){
        max = p1[j].second;
        maxI = j;
      }
    }
    if ( maxI < n){
      color[maxI] = true;
      ans ++;
    }
  }

  cout << ans << endl;

  return 0;
}