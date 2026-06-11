#include<bits/stdc++.h>
using namespace std;

int main() {
int N,x;
  cin >> N >> x;
  vector<int> a(N);
  for(int i=0; i<N; ++i) {
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
    int ans = 0;
  for(int i=0; i<N; ++i) {
    if(a.at(i)<=x){
      
      if(i==N-1){
        if(x==a.at(i)){
          ans++;
          break;
        }
      }
      else{
        ans++;
        x-=a.at(i);
      }
      
    }
    else{
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
      
    