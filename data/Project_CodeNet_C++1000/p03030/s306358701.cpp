#include<bits/stdc++.h>
using namespace std;
  
 
int main(){
  std::vector<tuple<string,int,int>> v;
  int N;
  cin >> N;
  for(int i=0;i<N;i+=1){
     int b,c;
     string a;
     cin >> a >> b;
     v.push_back(make_tuple(a,-b,i+1)); 
  }
  
  sort(v.begin(),v.end());
//   sort(v.begin(),v.end());
  for(auto x:v){
     cout << get<2>(x) <<endl ;
  }
}