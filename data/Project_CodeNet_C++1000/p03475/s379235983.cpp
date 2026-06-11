#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  cin>>A;
  vector<vector<int>>train(A-1,vector<int>(3));
  for(int i=0;i<A-1;i++){
    cin>>train.at(i).at(0);
    cin>>train.at(i).at(1);
    cin>>train.at(i).at(2);
  }
  for(int i=0;i<A-1;i++){
    int c;
    c=train.at(i).at(0)+train.at(i).at(1);
    for(int j=1;j<(A-i-1);j++){
      if(c<train.at(i+j).at(1)){
        c=train.at(i+j).at(1);
      }
      
      else if(c%train.at(i+j).at(2)!=0){
        c=train.at(i+j).at(2)*(c/train.at(i+j).at(2)+1);
      }
      c+=train.at(i+j).at(0);
    }
    cout<<c<<endl;
  }
  cout<<0<<endl;
}

    
