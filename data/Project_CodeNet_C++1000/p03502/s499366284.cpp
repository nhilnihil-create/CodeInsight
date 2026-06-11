#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

int main() {
  int n;
  int sum = 0; cin >> n;

  string num = to_string(n);
  for(int i = 0; i < num.size(); ++i){
    char x; int y;
    x = num.at(i);
    y = x -'0';
    sum += y;
  }

  if(n%sum==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}