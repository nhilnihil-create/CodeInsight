#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,alice=0,bob=0,tmp;
  cin >> n;
  vector<int> line(n);
  for(int i=0;i<n;i++){
    cin >> line.at(i);
  }
  for(int i=0;i<n-1;i++){
    for(int j=n-1;j>i;j--){
      if(line.at(j)>line.at(j-1)){
        tmp=line.at(j);
        line.at(j)=line.at(j-1);
        line.at(j-1)=tmp;
      }
    }
  }
  for(int i=0;i<n;i++){
      if((i+1)%2==1)alice+=line.at(i);
      else bob+=line.at(i);
  }
  cout << alice - bob << endl;
}
      