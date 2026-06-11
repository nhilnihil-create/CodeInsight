#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, k;
  cin >> a >> b >> k;
  set<int> s;
  for(int i=0; i<k; i++){
    if(a+i<=b) s.insert(a+i);
  }
  for(int i=0; i<k; i++){
    if(b-i>=a) s.insert(b-i);
  }
  vector<int> v(s.begin(), s.end());
  for(int i=0; i<int(v.size()); i++){
    cout << v[i] << endl;
  }
  return 0;
}
