#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >>H >>W;
  int N[H][W];
  for (int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>N[i][j];
    }
  }
  int tempH=0;//現在地
  int tempW=0;
  int flag=1;//右行時1 左行時0
  queue<pair<int,int>>Q;
  pair<int,int>P;
  while(1){
    //右行時(flag=1)
    if(flag){
      if(tempH== H-1 && tempW == W-1){
        //終点処理(右端終点）
        break;
      }
      else if(N[tempH][tempW]%2==0 && tempW != W-1){
        //普通に１個進める
        tempW++;
        continue;
      }
      else if(N[tempH][tempW]%2==0 && tempW == W-1){
        //行端処理1
        tempH++;
        flag=0;
        continue;
      }      
      else if(N[tempH][tempW]%2!=0 && tempW != W-1){
        //偶数化処理して普通に１個進める
        Q.push({tempH,tempW});
        Q.push({tempH,tempW+1});
        //cout<<tempH<<" "<<tempW<<" "<<tempH<<" "<<tempW+1<<endl;
        N[tempH][tempW+1]++;
        tempW++;
        continue;
      }
      else if(N[tempH][tempW]%2!=0 && tempW == W-1){
        //行端処理2
        Q.push({tempH,tempW});
        Q.push({tempH+1,tempW});        
        //cout<<tempH<<" "<<tempW<<" "<<tempH+1<<" "<<tempW<<endl;
        N[tempH+1][tempW]++;
        tempH++;
        flag=0;
        continue;
      }
    }
    if(flag == 0){
      if(tempH== H-1 && tempW == 0){
        //終点処理(左端終点）
        break;
      }
      else if(N[tempH][tempW]%2==0 && tempW != 0){
        //普通に１個進める
        tempW--;
        continue;
      }
      else if(N[tempH][tempW]%2==0 && tempW == 0){
        //行端処理2
        tempH++;
        flag=1;
        continue;
      }      
      else if(N[tempH][tempW]%2!=0 && tempW != 0){
        //偶数化処理して普通に１個進める
        Q.push({tempH,tempW});
        Q.push({tempH,tempW-1});        
        //cout<<tempH<<" "<<tempW<<" "<<tempH<<" "<<tempW-1<<endl;
        N[tempH][tempW-1]++;
        tempW--;
        continue;
      }
      else if(N[tempH][tempW]%2!=0 && tempW == 0){
        //行端処理2
        Q.push({tempH,tempW});
        Q.push({tempH+1,tempW});        
        //cout<<tempH<<" "<<tempW<<" "<<tempH+1<<" "<<tempW<<endl;
        N[tempH+1][tempW]++;
        tempH++;
        flag=1;
        continue;
      }
    } 
  }
  int temp=Q.size();
  cout<<temp/2<<endl;
  while(Q.size() != 0){
    P=Q.front();Q.pop();
    cout<<P.first+1<<" "<<P.second+1<<" ";
    P=Q.front();Q.pop();
    cout<<P.first+1<<" "<<P.second+1<<endl;
  }
    
  return 0;
}
