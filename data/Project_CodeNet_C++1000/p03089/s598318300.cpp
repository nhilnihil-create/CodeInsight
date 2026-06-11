#include <iostream>
#include <list>
using namespace std;


int main(void){
  int n, flg;
  list<int> b,ans;
  
  cin >> n;
  for(int i=0; i<n; i++){
    int t; cin >> t;
    b.push_front(t);
  }
  while (!b.empty()){
    flg=0;
    int i=n;
    for (auto itr=b.begin(); itr!=b.end(); itr++, i--){
//      cout << "(" << *itr << "," << i << ")";
      if (*itr==i){
//        cout << endl;
        ans.push_front(i);
        itr = b.erase(itr);
        n--;
        flg=1;
        break;
      }
    }
    if (!flg) break;
  }
  if (flg) {
    for (auto itr=ans.begin(); itr!=ans.end(); itr++) cout << *itr << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
