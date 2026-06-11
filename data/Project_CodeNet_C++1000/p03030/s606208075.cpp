#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<tuple<string, int, int>> v(n);
  
  for(int i = 0; i < n; i++){
    string a;
    int b;
    cin >> a >> b;
    v.at(i) = make_tuple(a,(-1)*b,i+1);
  }
  
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    int a;
    tie(ignore, ignore, a) = v.at(i);
    cout << a << endl;
  }
}