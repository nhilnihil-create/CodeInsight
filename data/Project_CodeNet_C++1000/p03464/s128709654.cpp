#include <iostream>
using namespace std;
#define int long long
signed main(){
  int K;
  cin>>K;
  int A[100010];
  for(int i=1;i<=K;i++){
    cin>>A[i];
  }
 
  //最終回が2人でなければ-1
  /*if(A[K] != 2){
    cout<<-1<<endl;
    return 0;
  }*/
  
  //最大人数　maxp　最小人数　minp
  int minp[100010];
  int maxp[100010];
  minp[K]=2;
  maxp[K]=2;
  int temp;
  //後ろから人数を決めながら遡る
  for(int i=K-1;i>=0;i--){
    if(maxp[i+1]%A[i+1] !=0 && minp[i+1]%A[i+1]!=0 && maxp[i+1]/A[i+1]-minp[i+1]/A[i+1]==0){
      cout<<-1<<endl;
      return 0;
    }
    
    //i+1の最大値と最小値におさまるA[i+1]の倍数の最小値
    minp[i]=((minp[i+1]-1)/A[i+1]+1)*A[i+1];
    /*if(temp>maxp[i+1]){
      cout<<-1<<endl;
      return 0;
    }*/
    //minp[i]=temp;

    maxp[i]=maxp[i+1]/A[i+1]*A[i+1]+A[i+1]-1;
    /*if(maxp[i]<minp[i]){
      cout<<-1<<endl;
      return 0;
    }*/
    
    //cout<<minp[i]<<" "<<maxp[i]<<endl;
  }
  cout<<minp[0]<<" "<<maxp[0]<<endl;
  return 0;
}
