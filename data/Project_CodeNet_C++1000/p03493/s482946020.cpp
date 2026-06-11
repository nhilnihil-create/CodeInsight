#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int sum=0;
  for(int i=0;i<3;i++){
    sum+=S.at(i)-'0';
  }
  cout << sum << endl;
}
    