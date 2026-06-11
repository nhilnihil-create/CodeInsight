#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, H, ans=0, sum=0; 
  cin >> N >> H;
  vector<long long> a(N), b(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i) >> b.at(i);
  }
  
  sort(a.begin(),a.end(),greater<long long>());
  sort(b.begin(),b.end(),greater<long long>());
  for(int i=0;i<N;i++){
    if(b.at(i) < a.at(0)) break;
    if(H<=0) break;
    H = H - b.at(i);
    ans++;
  }
  
  if(H<=0){
  }
  else {
    while(H>0){
      H = H - a.at(0);
      ans++;
    }
  }

  cout << ans << endl;
}