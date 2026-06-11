#include <iostream>
#include <set>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
//#define rep(i, n) for(int (i) = 0, TmP = (n); (i) < (int)TmP ; ++(i))
#define asort(v, n) sort((v), (v + n)) //Using array
#define vsort(v) sort((v).begin(), (v).end()) // Using vector
#define vint vector<int>
typedef long long ll;

using namespace std;

signed main(){
  int n; cin >> n;
  vector<string> list(n);
  rep(i, n) cin >> list[i];

  set<string> st;
  rep(i, n) st.insert(list[i]);
  if(st.size() != n){
    cout << "No" << endl;
    return 0;
  }

  rep(i, n - 1){
    if(list[i].back() != list[i + 1][0]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

}
