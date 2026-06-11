#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int>> a(h,vector<int>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>a.at(i).at(j);
  vector<vector<int>> s;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(j<w-1&&a.at(i).at(j)%2==1){
        a.at(i).at(j)--;
        a.at(i).at(j+1)++;
        s.push_back({i+1,j+1,i+1,j+2});
      }else if(i<h-1&&a.at(i).at(j)%2==1){
        a.at(i).at(j)--;
        a.at(i+1).at(j)++;
        s.push_back({i+1,j+1,i+2,j+1});
      }
    }
  }
  cout<<s.size()<<endl;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<4;j++)
      cout<<s.at(i).at(j)<<(j<3?" ":"");
    cout<<endl;
  }
}