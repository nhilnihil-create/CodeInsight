#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a[100];
  double ave=0;
  for(int i=0; i<N; i++){
    cin >> a[i];
    ave+=a[i];
  }
  ave = (double)ave/N;
  vector<pair<double, int> >ans;
  for(int i=0; i<N; i++){
    ans.push_back(make_pair(abs(a[i]-ave), i));
  }
  sort(ans.begin(), ans.end());
  cout << ans[0].second << endl;
  return 0;
}