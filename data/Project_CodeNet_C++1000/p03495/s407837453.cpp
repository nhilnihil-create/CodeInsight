#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int data[200010]={0}; //最大の数が200000なので余裕をもって
  int N; //データの数
  int K; //limitの数
  
  cin >>N>>K; //データの入力
  
  for (int i=0; i<N; i++)cin>>data[i]; //データの挿入
  
  int num[200010]={0}; //バケット用意
  
  for (int i=0; i<N;i++) num [data[i]]++; //それぞれの種類が何種あるか数える
  
  sort(num,end(num),greater<int>());//大きい順に並び変える

  int ans=0; //答え
  
    int i=0;
    int kind=0; //初期化
    while(num[i] != 0){//何種類あるかを答える
      kind++;
      i++;
    }

  if (kind > K)
    for(int j=K ; j<kind; j++) ans += num[j];
  
  cout <<ans <<endl;
}

    
      
      
      
      
  
  
  
  
  
