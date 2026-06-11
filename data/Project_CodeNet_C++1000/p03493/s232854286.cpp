#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int sum;
  if(s[0]== '1')sum++;
  if(s[1]== '1')sum++;
  if(s[2]== '1')sum++;
  
  cout << sum << endl;
}
