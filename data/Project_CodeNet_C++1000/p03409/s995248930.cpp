#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<P> red(n), blue(n);
  rep(i, n) cin >> red[i].first >> red[i].second;
  rep(i, n) cin >> blue[i].first >> blue[i].second;
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  vector<int> used(n);

  int ans = 0;
  rep(i, n) {
    int maxRed = -1;
    rep(j, n) {
      if(blue[i].first <= red[j].first) break;
      if(blue[i].second > red[j].second && !used[j]) {
        if(maxRed == - 1) maxRed = j;
        else if(red[maxRed].second < red[j].second) maxRed = j;
      }
    }
    if(maxRed != -1) {
      used[maxRed] = true;
      ans++;
    }
  }
  cout << ans << endl;
}