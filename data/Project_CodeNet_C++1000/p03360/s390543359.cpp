#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int k,sum=0;
  vector<int>a(3);
  for(int i=0; i<3; i++){
    cin >> a.at(i);
  }
  cin >> k;
  sort(a.begin(),a.end());
  for(int i=1; i<=k; i++){
    a.at(2)=a.at(2)*2;
  }
  sum=a.at(0)+a.at(1)+a.at(2);
  cout << sum << endl;
}
