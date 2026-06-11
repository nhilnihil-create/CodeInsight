#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pp=pair<ll,pair<int,int>>;
using Graph=vector<vector<pair<int,ll>>>;

int main(){
  int N;
  cin>>N;
  if(N==3){
    cout<<"2 5 63"<<endl;
  }else{
    vector<bool> ans(300001,false);
    int count=0;
    int i=2;
    ll sum=0;
    while(count<N-1){
      while(!(i%2==0||i%3==0)){
        i++;
      }
      if(N%4==2||(N%4==3&&N<10)){
        if(i==2||i==4){
          i++;
          continue;
        }
      }
      if(N%4==3&&N>=10){
        if(i==3){
          i++;
          continue;
        }
      }
      ans.at(i)=true;
      count++;
      sum+=(ll)i;
      i++;
    }
    ll nth=0;
    while(sum%6!=0||nth==0){
      nth++;
      sum++;
    }
    while(ans.at(nth)==true){
      nth+=6;
    }
    ans.at(nth)=true;
    for(int i=0;i<300001;i++){
      if(ans.at(i)){
        cout<<i<<" ";
      }
    }
    cout<<endl;
  }
}
