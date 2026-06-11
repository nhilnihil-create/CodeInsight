#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec(4);
	for (int i = 0; i < 4; i++) {
  	cin >> vec.at(i);
	}
  if(
  (count(vec.begin(),vec.end(),1) == 1) &&
  (count(vec.begin(),vec.end(),9) == 1) &&
  (count(vec.begin(),vec.end(),7) == 1) &&
  (count(vec.begin(),vec.end(),4) == 1)
    ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
