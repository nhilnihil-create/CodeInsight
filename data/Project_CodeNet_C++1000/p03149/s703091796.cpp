#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> n(4);
  for(int i=0;i<4;i++) {
    cin >> n.at(i);
  }
  sort(n.begin(), n.end());
  vector<int> ans={1,4,7,9};
  bool flag=true;
  for(int i=0;i<4;i++) {
    if(ans.at(i)!=n.at(i)) {
      flag=false;
      break;
    }
  }
  if(flag) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}