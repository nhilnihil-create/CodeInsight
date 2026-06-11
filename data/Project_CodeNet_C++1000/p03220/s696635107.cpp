#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){

  double n,t,a;

  cin >> n >> t >> a;

  vector<double> h(n);

  int min_idx = 0;

  for(int i=0;i<n;i++){
    cin >> h[i];
    h[i] = abs((t - h[i] * 0.006) - a);

    if(h[min_idx] > h[i]){
      min_idx = i;
    }
  }

  cout << min_idx + 1 << endl;


  for(int i=0;i<n;i++){
//    cout <<  h[i] << endl;
  }


}