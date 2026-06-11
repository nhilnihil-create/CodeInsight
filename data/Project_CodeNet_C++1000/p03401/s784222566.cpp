#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  vector<int64_t> A(n);
  for(int i=0;i<n;i++){
    cin>>A.at(i);
  }
//最初全部の経路を足す
//ポイントiを飛ばす。
//ポイントi-1～ポイントiとポイントi～ポイントi+1の距離を削る。
//ポイントi-1～i+1の距離を足す。
  int64_t sum=0;
  for(int i=0;i<n;i++){
    if(i==0)
      sum+=abs(A.at(i));
    else if(i==n-1)
      sum+=abs(A.at(i)-A.at(i-1))+abs(A.at(i));
    else
      sum+=abs(A.at(i)-A.at(i-1));
  }


  for(int i=0;i<n;i++){
    if(i==0){
        cout<<sum-(abs(A.at(i))+abs(A.at(i+1)-A.at(i)))+abs(A.at(i+1))<<endl;
    }
    else if(i==n-1){
        cout<<sum-(abs(A.at(i)-A.at(i-1))+abs(A.at(i)))+abs(A.at(i-1))<<endl;
    }
    else{
        cout<<sum-(abs(A.at(i)-A.at(i-1))+abs(A.at(i+1)-A.at(i)))+abs(A.at(i+1)-A.at(i-1))<<endl;
    }
  }

    return 0;
}


