#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int s;
  cin >> s;
  
  vector<int> a;
  a.push_back(s);	//初項をいれる
  
  int ibuff=s;
  vector<int>::iterator itr;
  for (long i=2; i<1000001L; i++) {
    //関数計算
    if (ibuff%2)	ibuff = 3*ibuff+1;
    else			ibuff /= 2;
    
    //数値があるか
    itr = find(a.begin(), a.end(), ibuff);
    //無いときは数値を追加する。見つかったらそのまま出力
    if (itr == a.end()) {
	    a.push_back(ibuff);
    } else {
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}