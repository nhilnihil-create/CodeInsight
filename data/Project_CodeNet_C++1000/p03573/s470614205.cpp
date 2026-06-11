#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector<int> v(3);
  rep(i,3){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  if(v[0]<v[1]){
    cout << v[0] << endl;
  }else{
    cout << v[2] << endl;
  }
}
