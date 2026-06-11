#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int>A(5);
  for(int i=0;i<5;i++){
    cin >> A.at(i);
  }
  vector<int>a(5);
  int MAX = 0;
  for(int i=0;i<5;i++){
    a.at(i) = (10 - A.at(i)%10)%10;
    MAX = max(a.at(i),MAX);
  }
  int ans = 0;
  for(int i=0;i<5;i++){
    ans += A.at(i) + a.at(i);
  }
  cout << ans - MAX << endl;
}
