#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int N = 0,M = 0;
  cin >> N;
  vector<string>A(N);
  set<string> set;
  rep(i,N){
    cin >> A[i];
    set.insert(A[i]);
  }
  if(N != set.size()){
    cout << "No";
    return 0;
  }
  rep(i,N - 1){
    M = A[i].size();
    if(A[i].at(M - 1) != A[i + 1].at(0)){
      cout << "No";
      return 0;
    }
  }
    cout << "Yes";
}