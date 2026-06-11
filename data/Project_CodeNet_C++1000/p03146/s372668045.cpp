#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  int N = 0;
  cin >> N;
  set<int> s;
  s.insert(N);
  rep(i,1000000){
    if(N % 2 == 0){
      N /= 2;
    }
    else{
      N = N * 3 + 1;
    }
    s.insert(N);
    if(s.size() != i+2){
      cout << s.size() + 1;
      return 0;
    }
  }
}