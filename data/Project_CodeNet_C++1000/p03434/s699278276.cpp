#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++){
    cin >> a.at(i);
  }
  
  int instance;
  for (int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      if (a.at(i) < a.at(j)){
        instance = a.at(i);
        a.at(i) = a.at(j);
        a.at(j) = instance;
      }
    }
  }
  int ans=0, flag=0;
  for (int i=0; i<N; i++){
    ans = flag==0 ? ans+a.at(i) : ans-a.at(i);
    flag = flag==0 ? 1 : 0;
  }
  cout << ans;
}