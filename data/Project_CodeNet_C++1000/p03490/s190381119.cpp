#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
bool judge(vector<int> vec,int goal){
  bool dp[16005][2];
  for(int i=0;i<16005;i++){
    for(int j=0;j<2;j++) dp[i][j]=false;
  }
  dp[8002][0]=true;
  for(int i=0;i<vec.size();i++){
    for(int j=0;j<16005;j++){
      if(dp[j][0]){
        dp[j+vec[i]][1]=true;
        dp[j-vec[i]][1]=true;
      }
    }
    for(int j=0;j<16005;j++){
      dp[j][0]=dp[j][1];
      dp[j][1]=0;
    }
  }
  return dp[goal+8002][0];
}
int main(){
  string s;
  cin>>s;
  int n=s.length();
  int gx,gy;
  cin>>gx>>gy;
  int i1=0;
  while(s[i1]!='T'&&i1<n) i1++;
  gx-=i1;
  vector<int> xvec,yvec;
  int cnt=0;
  bool f=false;
  for(int i=i1+1;i<n;i++){
    if(s[i]=='F') cnt++;
    else{
      if(f){
        xvec.push_back(cnt);
        f=false;
      }
      else{
        yvec.push_back(cnt);
        f=true;
      }
      cnt=0;
    }
  }
  if(cnt>0){
    if(f) xvec.push_back(cnt);
    else yvec.push_back(cnt);
  }
  if(judge(xvec,gx)&&judge(yvec,gy)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
