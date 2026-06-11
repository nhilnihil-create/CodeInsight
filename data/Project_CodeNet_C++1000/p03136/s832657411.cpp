#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int n,sum = 0;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; i++){
    cin >> l[i];
  }
  sort(l.begin(),l.end());
  for (int i = 0; i < n-1; i++){
    sum += l[i];
  }
  /*cout << sum << '\n';*/
  if (sum > l[n-1]){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
  return 0;
}