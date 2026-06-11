#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
typedef pair<int, int> P;
int main(){
  cin >> n;
  P pr[n], pb[n];
  for(int i=0 ; i<n ; i++){
    cin >> pr[i].fi >> pr[i].se;
  }
  for(int i=0 ; i<n ; i++){
    cin >> pb[i].fi >> pb[i].se;
  }
  sort(pr, pr+n); sort(pb, pb+n);
  priority_queue<P> que;
  int cnt = 0;
  bool used[200]={false};
  for(int i=0 ; i<n ; i++){
    int bx = pb[i].fi, by = pb[i].se;
    int k=-1;
    int hmi = -1;
    for(int j=0 ; j<n ; j++){
      int rx = pr[j].fi, ry = pr[j].se;
      if(rx<bx && ry<by && !used[j] && hmi<ry) {
        k = j;
        hmi = ry;
      }
    }
    if(k != -1){
        used[k] = true;
        cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
