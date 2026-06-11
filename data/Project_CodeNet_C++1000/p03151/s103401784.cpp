#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  ll Asum=0,Bsum=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    Asum+=A[i];
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
    Bsum+=B[i];
  }
  if(Asum<Bsum){
    cout << -1 << endl;
    return 0;
  }
  vector<int> dif(N);
  for(int i=0;i<N;i++){
    dif[i]=A[i]-B[i];
  }
  sort(dif.begin(),dif.end());
  ll count=0;
  ll ans=0;
  for(int i=0;i<N;i++){
    if(dif[i]<0){
      count+=dif[i];
      ans++;
    }
    else{
      break;
    }
  }
  if(ans==0){
    cout << 0 << endl;
    return 0;
  }
  for(int i=N-1;i>=0;i--){
    ans++;
    count+=dif[i];
    if(count>=0){
      break;
    }
  }
  cout << ans << endl;
  return 0;
}