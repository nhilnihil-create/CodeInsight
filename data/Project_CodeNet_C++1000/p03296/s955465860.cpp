#include<bits/stdc++.h>
using namespace std;
//define
typedef pair<int,int>pi;
#define int long long
#define elif else if
#define rep(x,y) for(int i=x;i<y;i++)
#define REP(x,y) for(int j=x;j<y;j++)
#define Rep(x,y) for(int k=x;k<y;k++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define vint vector<int>
#define vvint vector<vector<int>>
#define vtr vector<string>
#define vvtr vector<vector<string>>
#define vhar vector<char>
#define vvhar vector<vector<char>>
#define mod 100000007
#define elif else if
#define str string
int digitsum(int a){
  int b=0;
  while(a){
    b+=a%10;
    a/=10;
  }
  return b;
}
signed main(){
  int N,M,O,P=0,c=0,co=0,cou=0,minN=mod;
  double D,Do;
  char C,Ca;
  str S,T;
  cin>>N;
  vint slime(N);rep(0,N)cin>>slime[i];
  rep(0,N-1){
    if(slime[i]==slime[i+1]){
      slime[i+2]!=slime[i]+2?slime[i+1]=slime[i]+2:slime[i+1]=slime[i]+3;
      c++;
    }
  }
  cout<<c<<endl;
}
