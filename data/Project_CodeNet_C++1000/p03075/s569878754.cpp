#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  vector<int> ant(5);
  rep(i,5){
    cin >> ant.at(i);
  }
  int k = 0;
  cin >> k;
  sort(ant.begin(),ant.end());
  if(ant.at(4) - ant.at(0) <= k){
    cout << "Yay!" << endl;
  }
  else{
    cout <<":(" << endl;
  }
}
  
  
    