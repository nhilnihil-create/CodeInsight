#include <bits/stdc++.h>
using namespace std;
static const int INF=9;

int main(){
  int N,M;
  cin>>N>>M;
  int E[N][N];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j){
        E[i][j]=0;
      }
      else E[i][j]=INF;
    }
  }
  vector <pair<int,int>>vec(M);
  for(int i=0;i<M;i++){
    cin>>vec[i].first>>vec[i].second;
    E[vec[i].first-1][vec[i].second-1]=0;
    E[vec[i].second-1][vec[i].first-1]=0;   
  }
  
  /*for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<E[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
  */
  
  int ans=0;

  for(int i=0;i<M;i++){
    //辺を取り除く
    E[vec[i].first-1][vec[i].second-1]=INF;
    E[vec[i].second-1][vec[i].first-1]=INF;
    //辺の両端の距離を計算する
    for(int k=0;k<N;k++){
      for(int j=0;j<N;j++){
        for(int l=0;l<N;l++){
          if(E[j][l]>E[j][k]+E[k][l]) E[j][l]=E[j][k]+E[k][l];
        }
      }
    }
    
    for(int p=0;p<N;p++){
      for(int q=0;q<N;q++){
        if(E[p][q]==0) E[q][p]=0;
      }
    }
   
    //cout<<"&&"<<E[3][4]<<" "<<E[5][4]<<E[4][5]<<endl;
    if(E[vec[i].first-1][vec[i].second-1]==INF){
      ans++;
      //cout<<"#"<<vec[i].first-1<<" "<<vec[i].second-1<<endl;
    }
    //もとに戻す
    for(int p=0;p<N;p++){
      for(int q=0;q<N;q++){
              if(p==q){
        E[p][q]=0;
      }
      else E[p][q]=INF;
      }
    }
    
    for(int p=0;p<M;p++){
      E[vec[p].first-1][vec[p].second-1]=0;
      E[vec[p].second-1][vec[p].first-1]=0; 
    }
  }

  cout<<ans<<endl;
  return 0;
}

