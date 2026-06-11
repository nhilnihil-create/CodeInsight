#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin>>a;
  string p1,p2,p3;
  cin>>p1>>p2>>p3;
  
  int answer=0;
  vector<char> vec(3);
  
  for(int i=0;i<a;i++){
    vec.at(0)=p1.at(i);
    vec.at(1)=p2.at(i);
    vec.at(2)=p3.at(i);
    
    sort(vec.begin(),vec.end());
    
    if(vec.at(0)!=vec.at(1)){
      answer++;
    }
    if(vec.at(1)!=vec.at(2)){
      answer++;
    }
  }
  
  cout<<answer<<endl;
}
