#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
using namespace std;

bool check (string s){
  int n = s.length();
  if (n%2==1){
    return false;
  }
  else {
    return (s.substr(0,n/2-1)==s.substr(n/2));
  }
}

int main(){
  long long x, y;
  cin >> x >> y;

  int cnt = 0;
  long long index = x;
  while (index<=y){
    index *= 2;
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
