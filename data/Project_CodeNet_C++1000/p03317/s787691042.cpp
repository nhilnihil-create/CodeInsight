#include<bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main(){
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  int ru = k - 2, div = k - 1;
  cout << (n - 1 + ru) / div << endl;
}