#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec={0,0,0,0};
  int p;
  for(int i=0;i<6;i++){
    cin>>p;
    vec.at(p-1)++;
  }
  sort(vec.begin(),vec.end());
  
  if(vec.at(0)==1&&vec.at(1)==1&&vec.at(2)==2&&vec.at(3)==2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}