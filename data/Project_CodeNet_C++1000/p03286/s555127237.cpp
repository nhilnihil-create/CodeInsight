#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m,o;
  cin >> n;
  m = n;
  o = n;
  int sum = 0;
  vector<int> a;

  
  
  int i = 0;
  while(1){
    
    if(m % -2 == 0){
      a.push_back(0);
      m /= -2;
      
    }
    else{
      a.push_back(1);
      m--;
      m /= -2;
      int b = pow(-2,i);
      sum += b;
    }
    
    //cout << sum << endl;

    if(sum == o){
      break;
    }
    
    i++;
  }
  
  int m1 = a.size();
  reverse(a.begin(),a.end());
  REP(i,m1) cout << a[i];
  
  
}
