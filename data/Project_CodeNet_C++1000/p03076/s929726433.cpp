#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> cook(5);
  for(int i=0;i<5;i++) cin>>cook.at(i);
  vector<vector<int>> A;
  vector<int> ans={0,1,2,3,4};
  do{ A.push_back(ans); }while(next_permutation(ans.begin(),ans.end()));
  priority_queue<int,vector<int>,greater<int>> time;
  for(int i=0;i<120;i++){
    int X=0;
    for(int j=0;j<4;j++){
      if(cook.at(A.at(i).at(j))%10==0) X+=cook.at(A.at(i).at(j));
      else X+= (cook.at(A.at(i).at(j))/10+1)*10;
    }
    X+=cook.at(A.at(i).at(4));
    time.push(X);
  }
  cout<<time.top()<<endl;
}
