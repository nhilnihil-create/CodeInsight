#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int a,b,k;
  cin >> a >> b >> k;
  set<int> s;
  for(int i = a; i < a + k; i++){
    if(i <= b)s.insert(i);
  }
  for(int i = b; i > b-k; i--){
    if(i >= a)s.insert(i);
  }
  while(!s.empty()){
    int m = *begin(s);
    cout << m << endl;
    s.erase(m);
  }
}