#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=0;
  cin >> n;
  vector<int64_t>ryuka(n+1);
  ryuka.at(0)=2;
  ryuka.at(1)=1;
  for(int i=0;i<=n;i++){
    if(i>1){
      ryuka.at(i) += ryuka.at(i-2)+ryuka.at(i-1);
    }
  }
  cout << ryuka.at(n) << endl;
}