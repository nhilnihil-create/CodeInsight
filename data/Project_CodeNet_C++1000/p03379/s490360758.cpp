#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    b.at(i) = a.at(i);
  }
  sort(b.begin(), b.end());
  int cnt1 = b.at(n/2-1), cnt2 = b.at(n/2);
  for(int i = 0; i < n; i++){
    if(cnt1 == cnt2) cout << cnt1 << endl;
    else if(a.at(i) <= cnt1) cout << cnt2 << endl;
    else if(a.at(i) >= cnt2) cout << cnt1 << endl;
  }
}