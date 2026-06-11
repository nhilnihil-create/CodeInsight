#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main()
{
  int n; cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }

  bool escape = false;

  for(int i = 0; escape == false ;++i) {
    for(int j = 0; j<n; ++j) {
      if(v[j]%2 == 1) {
        cout << i << endl;
        escape = true;
        break;
      }

      v[j] = v[j] / 2;
    }

  }

}