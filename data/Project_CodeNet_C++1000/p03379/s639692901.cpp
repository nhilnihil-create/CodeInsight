#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  vector<P> a;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    a.push_back(make_pair(x,i));
  }
  sort(a.begin(), a.end());
  int ans[n];
  for(int i=0; i<n; i++){
    if(i<n/2) ans[a[i].second] = a[n/2].first;
    else ans[a[i].second] = a[n/2-1].first;
  }
  for(int i=0; i<n; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
