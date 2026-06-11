#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

string s;

int main(){
  cin >> s;
  string left = s, right = s;
  reverse(right.begin(), right.end());
  //cerr<< left << " "<< right << endl;
  
  int res = 0;
  for(int i = 0; i < (left.size() + 1) / 2; i++){
    char r = right.at(i), l = left.at(i);
    int n = left.size();
    //cerr << i << " "<< n - i <<" ";
    if(r == l){
      //cerr << endl;
      continue;
    }
    if(r != 'x' && l != 'x'){ //２つが異なる文字で、かつどちらもxでない
      res = -1;
      cerr << "break" << endl;
      break;
    }
    if(r == 'x'){
      right.insert(n - i, "x");
      left.insert(i, "x");
    }else if(l == 'x'){
      right.insert(i, "x");
      left.insert(n - i, "x");
    }
    //cerr << left << " "<< right << endl;
    res++;
  }
  cout << res << endl;
  return 0;
}
