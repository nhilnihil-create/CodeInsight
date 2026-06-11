#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >>n;
  vector<vector<int>>vec(2,vector<int>(n));
  for (int i=0;i<2;i++){
    for(int j=0;j<n;j++){
      cin >> vec.at(i).at(j);
    }
  }
  int p=0;
  for(int i=0;i<n;i++){
    int sum1=0;
    int sum2=0;
    int sum=0;
    for(int j=0;j<n;j++){
      if(i>=j){
        sum1+=vec.at(0).at(j);
      }
      if(i<=j){

      sum2+=vec.at(1).at(j);
      }
    }
    sum=sum1+sum2;
    p=max(p,sum);
  }
  cout << p <<endl;
}