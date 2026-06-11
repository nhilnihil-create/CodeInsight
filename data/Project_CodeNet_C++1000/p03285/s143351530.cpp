#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

//	vector<int> a(n);

  int n;
 
  cin >> n;

  int cnt=0;

  for(int i=0;i<=25;i++){
    for(int j=0;j<=14;j++){
      if(i*4 + j*7 == n){
        cnt = cnt + 1;
      }
    }
  }

  if(cnt != 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}