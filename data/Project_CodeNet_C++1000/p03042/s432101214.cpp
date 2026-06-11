#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<char>vec(4);
  for(ll i=0;i<4;i++){
    cin>>vec.at(i);
  }
  vector<ll>veco(2,0);
  if(vec.at(0)=='0'){
    if(vec.at(1)!='0'){
      veco.at(1)=1;
    }
  }
  if(vec.at(0)=='1'){
    if(vec.at(1)=='0'||vec.at(1)=='1'||vec.at(1)=='2'){
      veco.at(1)=1;
    }
  }
  if(vec.at(2)=='0'){
    if(vec.at(3)!='0'){
      veco.at(0)=1;
    }
  }
  if(vec.at(2)=='1'){
    if(vec.at(3)=='0'||vec.at(3)=='1'||vec.at(3)=='2'){
      veco.at(0)=1;
    }
  }
  vector<ll>yymm={1,0};
  vector<ll>mmyy={0,1};
  if(veco==yymm){
    cout<<"YYMM"<<endl;
  }
  else if(veco==mmyy){
    cout<<"MMYY"<<endl;
  }
  else if(veco.at(0)+veco.at(1)==2){
    cout<<"AMBIGUOUS"<<endl;
  }
  else{
    cout<<"NA"<<endl;
  }
  return 0;
  
}
