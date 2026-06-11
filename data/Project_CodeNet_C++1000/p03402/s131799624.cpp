#include <bits/stdc++.h>
using namespace std;

//白色の連結成分がAつ、黒色の連結成分が1つになるような49*49グリッドを作る
void grid(int A,vector<vector<char>> &color){

  for(int i=0;i<49;++i){
    for(int j=0;j<49;++j){
      if(i==0 || i==48 || j==0 || j==48) color[i][j]='#';
      else color[i][j]='.';
    }
  }

    int count=0;
    while(count<24 && count<A){
      for(int i=0;i<49;++i) color[i][2*count]='#';
      ++count;
    }

    if(A-24>=0){
      int p=(A-24)/24;
      int r=(A-24)%24;
      for(int i=0;i<p;++i){
        for(int j=0;j<49;++j){
        color[2*i+2][j]='#';
        }
      }

      for(int j=0;j<r;++j){
      color[2*p+2][2*j+1]='#';
      }
    }
}

int main(){
  //in
  int A,B;
  cin>>A>>B;
  vector<vector<char>> white(49,vector<char>(49)),black(49,vector<char>(49));

  //paint
  grid(A,white);
  grid(B,black);
  for(int i=0;i<49;++i){
    for(int j=0;j<49;++j){
      if(black[i][j]=='#') black[i][j]='.';
      else if(black[i][j]=='.') black[i][j]='#';
    }
  }

  //out
  if(A==1){
    cout<<49<<" "<<49<<endl;
    for(int i=0;i<49;++i){
      for(int j=0;j<49;++j){
        if(j==48) cout<<black[i][j]<<endl;
        else cout<<black[i][j];
      }
    }
  }
  else if(B==1){
    cout<<49<<" "<<49<<endl;
    for(int i=0;i<49;++i){
      for(int j=0;j<49;++j){
        if(j==48) cout<<white[i][j]<<endl;
        else cout<<white[i][j];
      }
    }
  }
  else{
    cout<<98<<" "<<49<<endl;
    grid(A-1,white);
    grid(B-1,black);

    for(int i=0;i<49;++i){
      for(int j=0;j<49;++j){
        if(black[i][j]=='#') black[i][j]='.';
        else if(black[i][j]=='.') black[i][j]='#';
      }
    }
    for(int i=0;i<49;++i){
      for(int j=0;j<49;++j){
        if(j==48) cout<<white[i][j]<<endl;
        else cout<<white[i][j];
      }
    }
    for(int i=0;i<49;++i){
      for(int j=0;j<49;++j){
        if(j==48) cout<<black[i][j]<<endl;
        else cout<<black[i][j];
      }
    }
  }

}