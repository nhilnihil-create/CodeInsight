#include <bits/stdc++.h>
//#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair
using namespace std;

int main(){
  string str;
  cin >> str;
  int count = 0;

  for(int i = 0;i < str.size();i++){
    if(str.substr(i,1) == "x")count++;
  }

  if(count > 7)cout << "NO" << endl;
  else cout << "YES" << endl;
}