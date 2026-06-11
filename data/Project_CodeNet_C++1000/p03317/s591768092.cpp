#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  int i = 0;
  while (cnt < n){
    if (i == 0){
      cnt += k;
      i++;
      continue;
    }
    cnt += k - 1;
    i++;
  }
  cout << i << endl;
}
