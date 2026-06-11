#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,tmp,cnt=1;
  cin >> n;
  vector<int> mochis(n);
  for(int i=0;i<n;i++){
    cin >> mochis.at(i);
  }
  for(int i=0;i<n-1;i++){
    for(int j=n-1;j>i;j--){
      if(mochis.at(j)<mochis.at(j-1)){
        tmp=mochis.at(j);
        mochis.at(j)=mochis.at(j-1);
        mochis.at(j-1)=tmp;
      }
    }
  }
  for(int i=0;i<n-1;i++){
    if(mochis.at(i)<mochis.at(i+1))cnt++;
  }
  cout << cnt << endl;
}