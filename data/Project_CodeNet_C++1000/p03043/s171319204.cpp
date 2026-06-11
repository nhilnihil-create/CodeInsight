#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<int>a(n+1,0);
  int size=min(n+1,k);
  for(int i=1;i<size;i++){
    a.at(i)=1;
  }
  int kk=0;
  int tmpkk=1;
  while(tmpkk<k){
    tmpkk*=2;
    kk++;
  }
  for(int ii=1;ii<=kk;ii++){
    int i=1;
    while(i*pow(2,(ii))<k){
      a.at(i)++;
      i++;
      if(i==n+1)break;
    }
  }
  double ans=0;
  for(int i=1;i<=n;i++){
    double anstmp=1.0/n;
    for(int j=0;j<a.at(i);j++){
      anstmp/=2.0;
    }
    ans+=anstmp;
  }
  cout<< fixed << setprecision(15) <<ans<<endl;
}