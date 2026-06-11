#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<string,int,int>> t;
  for(int i = 0;i < n;i++){
    string a;
    int b;
    cin >> a >> b;
    t.emplace_back(a,100-b,i);
  }
  sort(t.begin(),t.end());
  for(int i = 0;i < n;i++){
    cout << get<2>(t[i]) + 1 << endl;
  }
  
}
