#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;cin>>n;
  map<char,int64_t>a;
  a['M']=a['A']=a['R']=a['C']=a['H']=0;
  string tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(a.count(tmp.at(0))){
      a.at(tmp.at(0))++;
    }
  }
  int64_t ans=0;
  vector<int64_t>aa(5);
  aa.at(0)=a['M'];
  aa.at(1)=a['A'];
  aa.at(2)=a['R'];
  aa.at(3)=a['C'];
  aa.at(4)=a['H'];
  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      for(int k=j+1;k<5;k++){
        ans+=aa.at(i)*aa.at(j)*aa.at(k);
      }
    }
  }
  cout <<ans<<endl;
}