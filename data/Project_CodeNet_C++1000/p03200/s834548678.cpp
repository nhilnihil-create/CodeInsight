#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
  string S;
  cin >> S;
  ll count_num = 0;
  ll count_index = 0;
  for(int i=0; i<S.length();i++){
    if(S.at(i) == 'W'){
      count_index += count_num;
    }else{
      count_num += 1;
    }
  }
  cout << count_index << endl;
}