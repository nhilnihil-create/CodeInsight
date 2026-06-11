#include <bits/stdc++.h>
using namespace std;

int main(){
  bitset<3> s;
  cin >> s;
  int count = 0;
  for(int i = 0; i < 3; i++){
    if(s.test(i)) count++;
  }
  cout << count << endl;
}
  