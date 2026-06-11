#include<bits/stdc++.h>

using namespace std;
int main(){
	string s; cin>>s;
  int X,Y; cin>>X>>Y;
  vector<int> x(4001,0);
  vector<int> y(4001,0);
  int turn=0,cntx=0,cnty=0;
  for(int i=0;i<s.size();i++){
  	if(turn%2==0){//
    	if(s[i]=='F') x[cntx]++;
        else{
          turn++;
          cntx++;
        }
    }else{//
    	if(s[i]=='F') y[cnty]++;
        else{
          turn++;
          cnty++;
        }
  	}
  }
  
  vector<vector<bool>> dpx(cntx+1,vector<bool>(16001,false));
  vector<vector<bool>> dpy(cnty+1,vector<bool>(16001,false));
  if(s[0]=='F'){
    int tmp=x[0];
    dpx[0][8000+tmp]=true;
    for(int i=1;i<=cntx;i++){
      for(int j=0;j<=16000;j++){
        tmp=x[i];
        if((j-tmp>=0 && dpx[i-1][j-tmp]==true) || (j+tmp<=16000 && dpx[i-1][j+tmp]==true)){
          dpx[i][j]=true;
        }
      }
    }
    tmp=y[0];
    dpy[0][8000+tmp]=true;
    dpy[0][8000-tmp]=true;
    for(int i=1;i<=cnty;i++){
      for(int j=0;j<=16000;j++){
        tmp=y[i];
        if((j-tmp>=0 && dpy[i-1][j-tmp]==true) || (j+tmp<=16000 && dpy[i-1][j+tmp]==true)){
          dpy[i][j]=true;
        }
      }
    }
    if(dpx[cntx][8000+X] && dpy[cnty][8000+Y]) printf("Yes");
    else printf("No");
  }
  else{//最初ターン
  	int tmp=x[0];
    dpx[0][8000+tmp]=true;
    dpx[0][8000-tmp]=true;
    for(int i=1;i<=cntx;i++){
      for(int j=0;j<=16000;j++){
        tmp=x[i];
        if((j-tmp>=0 && dpx[i-1][j-tmp]==true) || (j+tmp<=16000 && dpx[i-1][j+tmp]==true)){
          dpx[i][j]=true;
        }
      }
    }
    tmp=y[0];
    dpy[0][8000+tmp]=true;
    dpy[0][8000-tmp]=true;
    for(int i=1;i<=cnty;i++){
      for(int j=0;j<=16000;j++){
        tmp=y[i];
        if((j-tmp>=0 && dpy[i-1][j-tmp]==true) || (j+tmp<=16000 && dpy[i-1][j+tmp]==true)){
          dpy[i][j]=true;
        }
      }
    }
    if(dpx[cntx][8000+X] && dpy[cnty][8000+Y]) printf("Yes");
    else printf("No");
  }
}
