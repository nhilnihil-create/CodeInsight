#include<bits/stdc++.h>
using namespace std;

bool solve(vector<tuple<int,int,int>>&a){
  bool ans=true;
  int x=0,y=0,t=0;
  for(int i=0;i<a.size();i++){
    if(abs(get<1>(a.at(i))-x)+abs(get<2>(a.at(i))-y)>get<0>(a.at(i))-t)
      ans=false;
    if(((get<0>(a.at(i))-t)-(abs(get<1>(a.at(i))-x)+abs(get<2>(a.at(i))-y)))%2!=0)
      ans=false;
    x=get<1>(a.at(i));
    y=get<2>(a.at(i));
    t=get<0>(a.at(i));
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  vector<tuple<int,int,int>>a(n);
  for(int i=0;i<n;i++)
    cin >> get<0>(a.at(i)) >> get<1>(a.at(i)) >> get<2>(a.at(i));
  cout << (solve(a)?"Yes":"No") << endl;
  return 0;
}