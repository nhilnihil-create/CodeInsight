#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  vector<P> cm(m);
  for(int i=0; i<m; ++i) cin >> cm[i].second >> cm[i].first;
  sort(an.begin(),an.end());
  sort(cm.begin(),cm.end());
  ll ans = 0;
  for(int i=0; i<n; ++i){
    int s1 = an.size()-1;
    int s2 = cm.size()-1;
    if(s2 == -1 || an[s1] >= cm[s2].first){
      ans += an[s1];
      an.pop_back();
    }else{
      ans += cm[s2].first;
      --cm[s2].second;
      if(cm[s2].second <=0) cm.pop_back();
    }
  }
  cout << ans << endl;
}