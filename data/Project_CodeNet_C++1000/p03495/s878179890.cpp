#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  
  vector<int> ck(n);
  
  REP(i,n){
    int b;
    cin >> b;
    ck[b-1]++;
  }
  
  sort(ck.begin(),ck.end(), greater<int>());
  
  int cnt = k;
  int sum = 0;
  
  REP(i,n){
    if(k == 0) break;
    k--;
    sum += ck[i];
  }
  
  cout << n-sum << endl;
    

              
}