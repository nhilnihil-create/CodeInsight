# include <bits/stdc++.h>
using namespace std;

int main(){
  int N, T, A;
  cin >> N >> T >> A;
  int H[N];
  for (int i=0; i<N; i++){
    cin >> H[i];
  }
  double temp[N], diff[N];
  double min_diff=1000000;
  int ans=0;
  for (int i=0; i<N; i++){
    temp[i]=T-H[i]*0.006;
    if (temp[i]>A){
      diff[i]=temp[i]-A;
    }
    else {
      diff[i]=A-temp[i];
    }
    if (min_diff>=diff[i]){
      min_diff=diff[i];
      ans=i+1;
    }
  }
  cout << ans << endl;
}