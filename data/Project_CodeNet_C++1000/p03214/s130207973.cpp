#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  int sum=0;
  for(int i=0;i<N;i++){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  double average=(double)sum/N;
  int ans;
  double diff=1e9;
  for(int i=0;i<N;i++){
    if(diff>abs(a.at(i)-average)){
      diff = abs(a.at(i)-average);
      ans=i;
    }
  }
  cout << ans << endl;
  return 0;
}
