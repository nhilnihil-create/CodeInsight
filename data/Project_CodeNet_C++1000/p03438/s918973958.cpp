#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N, suma = 0, sumb = 0; cin >> N;
  vector<lint> a(N), b(N);
  for(lint i = 0; i < N; i++) cin >> a[i], suma += a[i];
  for(lint i = 0; i < N; i++) cin >> b[i], sumb += b[i];
  lint counts1 = 0, counts2 = 0;
  for(lint i = 0; i < N; i++){
    if(a[i] < b[i]) counts1 += ceil(double(b[i] - a[i]) / double(2));
    if(a[i] > b[i]) counts2 += (a[i] - b[i]);
  }
  if(max(counts1, counts2) <= (sumb - suma)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
