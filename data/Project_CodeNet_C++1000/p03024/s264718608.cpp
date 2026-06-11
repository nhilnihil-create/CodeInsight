#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll=long long;
using pp=pair<int,pair<int,int>>;

int main(){
  string S;
  cin>>S;
  int k=S.size();
  int ans=0;
  for(int i=0;i<k;i++){
    if(S.at(i)=='x'){
      ans++;
    }
  }
  if(ans<8){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
