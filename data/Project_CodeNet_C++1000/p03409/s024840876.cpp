#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = 	{1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main() {
  int n;
  cin >> n;
  int c=0;
  vector<pair<int,int>> a(n);
  vector<pair<int,int>> b(n);
  rep(i,n)
    cin >> a.at(i).second >> a.at(i).first;
  sort(all(a));
  reverse(all(a));
  rep(i,n)
    cin >> b.at(i).first >> b.at(i).second;
  sort(all(b));
  rep(i,n){
    rep(j,n){
      if(((b.at(i).first)>(a.at(j).second))&&((b.at(i).second)>(a.at(j).first))){
        a.at(j)=make_pair(300,300);
        c++;
        break;
      }
    }
  }
  
  cout << c << endl;
}
      
    