#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  long long int h,w;
  cin>>h>>w;
  vector<vector<char>> grid(h,vector<char>(w));
  long long int black=0;
  long long int white=0;
  for(long long int i=0; i<h; i++){
    for(long long int j=0; j<w; j++){
      cin>>grid.at(i).at(j);
      if(grid.at(i).at(j)=='.'){
        white++;
      }else{
        black++;
      }
    }
  }

  vector<vector<long long int>> dist(h,vector<long long int>(w,-1));
  dist.at(0).at(0)=0;
  queue<pair<long long int,long long int>> que;
  que.push(make_pair(0,0));
  while(!que.empty()){
    long long int x=que.front().second;
    long long int y=que.front().first;
    que.pop();
    if(x!=0&&grid.at(y).at(x-1)=='.'&&dist.at(y).at(x-1)==-1){
      que.push(make_pair(y,x-1));
      dist.at(y).at(x-1)=dist.at(y).at(x)+1;
    }
    if(x!=w-1&&grid.at(y).at(x+1)=='.'&&dist.at(y).at(x+1)==-1){
      que.push(make_pair(y,x+1));
      dist.at(y).at(x+1)=dist.at(y).at(x)+1;
    }
    if(y!=0&&grid.at(y-1).at(x)=='.'&&dist.at(y-1).at(x)==-1){
      que.push(make_pair(y-1,x));
      dist.at(y-1).at(x)=dist.at(y).at(x)+1;
    }
    if(y!=h-1&&grid.at(y+1).at(x)=='.'&&dist.at(y+1).at(x)==-1){
      que.push(make_pair(y+1,x));
      dist.at(y+1).at(x)=dist.at(y).at(x)+1;
    }
  }
  if(dist.at(h-1).at(w-1)==-1){
    cout<<-1<<endl;
  }else{
    long long int ans=white-dist.at(h-1).at(w-1)-1;
    cout<<ans<<endl;
  }
}