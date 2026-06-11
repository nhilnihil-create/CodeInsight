#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  bool xdp[2][16050]={};
  bool ydp[2][16050]={};
  for(int i=0;i<2;i++)
    for(int j=0;j<16050;j++){
      xdp[i][j]=false;
      ydp[i][j]=false;
    }
  string s;cin>>s;
  int x,y;
  cin>>x>>y;
  ydp[0][8010]=true;
  vector<vector<int> >pii(2);
  int cnt=0;
  int popo=0;
  while(s[popo]=='F'){
    cnt++;
    popo++;
  }
  xdp[0][8010+cnt]=true;
  bool flag=true;
  cnt=0;
  int tcnt=0;
  for(int i=popo;i<s.size();){
    tcnt=0;
    cnt=0;
    while(s[i]=='T'&&i<s.size()){
      tcnt++;
      //  cout<<"!"<<endl;
      i++;
    }
    if(i==s.size())
      break;
    if(tcnt%2==0){
      if(flag){
	while(s[i]=='F'&&i<s.size()){
	  cnt++;
	  i++;
	}
	pii[0].pb(cnt);
      }else{
	while(s[i]=='F'&&i<s.size()){
	  cnt++;
	  i++;
	}
	pii[1].pb(cnt);
      }
    }else{
      if(flag){
	while(s[i]=='F'&&i<s.size()){
	  cnt++;
	  i++;
	}
	pii[1].pb(cnt);
	flag=false;
      }else{
	while(s[i]=='F'&&i<s.size()){
	  cnt++;
	  i++;
	}
	pii[0].pb(cnt);
	flag=true;
      }
    }
  }
  for(int i=0;i<pii[0].size();i++){
    for(int j=0;j<16050;j++){
      if(xdp[i%2][j]){
	//	cout<<j<<" ";
	xdp[(i+1)%2][j-pii[0][i]]=true;
	xdp[(i+1)%2][j+pii[0][i]]=true;
      }
      xdp[i%2][j]=false;
    }
  }
  //cout<<endl;
  for(int i=0;i<pii[1].size();i++){
    for(int j=0;j<16050;j++){
      if(ydp[i%2][j]){
	//cout<<j<<" ";
	ydp[(i+1)%2][j-pii[1][i]]=true;
	ydp[(i+1)%2][j+pii[1][i]]=true;
      }
      ydp[i%2][j]=false;
    }
  }
  cout<<endl;
  if((xdp[(pii[0].size())%2][x+8010]==true)&&(ydp[(pii[1].size())%2][y+8010]==true))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
