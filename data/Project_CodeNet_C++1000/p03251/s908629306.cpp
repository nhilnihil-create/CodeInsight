#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<int> listA(n);
  vector<int> listB(m);
  for(int i=0; i<n; i++) {
    cin >> listA.at(i);
  }
  for(int i=0; i<m; i++) {
    cin >> listB.at(i);
  }
  sort(listA.begin(),listA.end());
  sort(listB.begin(),listB.end());
  if(listA.back() < listB.at(0)) {
    int s=listA.back()+1;
    int e=listB.at(0);
    for(int i=s; i<=e; i++) {
      if(x < i && i <= y) {
        cout << "No War" << endl;
        return 0;
      }
    }
  }
  cout << "War" << endl;
}