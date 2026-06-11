#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec(4);
	for (int i = 0; i < 4; i++) {
  	cin >> vec.at(i);
	}
  auto beg = vec.begin();
  auto end = vec.end();
  if(
  count(beg,end,1) == 1 &&
  count(beg,end,9) == 1 &&
  count(beg,end,7) == 1 &&
  count(beg,end,4) == 1
    ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
