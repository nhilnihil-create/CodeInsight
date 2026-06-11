#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> A(6);
  for(int i = 0; i < 6; i++) cin >> A.at(i);

  multiset<int> Path;
  for(int i = 0; i < 6; i++) Path.insert(A.at(i));
 
  if(Path.count(1) == 3 || Path.count(2) == 3 || Path.count(3) == 3 || Path.count(4) == 3){
    cout << "NO" << endl;
    return 0;
  }
cout << "YES" << endl;
}