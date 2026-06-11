#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> ans = { 1, 4, 7, 9};
  vector<int> N(4);
  for (int i = 0; i < 4; i++){
    cin >> N.at(i);
  }
  sort(N.begin(),N.end());
  if (N == ans)
    cout << "YES" << endl;
  else cout << "NO" << endl;
}