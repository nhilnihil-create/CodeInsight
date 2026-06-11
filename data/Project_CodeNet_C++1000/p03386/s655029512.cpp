#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ar array
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  set<int> s;
  int A = a;
  for(int i=0; i<c; i++) if(a<=b) s.insert(a++);
  for(int i=0; i<c; i++) if((b+1)-c>=A)s.insert((++b)-c);
  for(auto x : s){
    cout << x << '\n';
  }
  return 0;
}
