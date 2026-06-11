#include<iostream>
using namespace std;
typedef long long ll;
bool check(ll x, ll y,char c,string s[100]){
  for(ll i=-1;i<=1;i++){
    for(ll j=-1;j<=1;j++){
      if(i==0&&j==0) continue;
      if(x+i<0||y+j<0||x+i>=100||y+j>=100) continue;
      if(s[x+i][y+j]==c) return false;
    }
  }
  return true;
}
signed main(){
  ll a,b,tmp=0;
  string s[100];
  cin >> a >> b;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      tmp++;
      if(i<50){
        s[i]+='.';
      }else{
        s[i]+="#";
      }
    }
  }
  cout <<"100 100\n";
  for(int i=0;i<49;i++){
    for(int j=0;j<100;j++){
      if(b-1>0&&check(i,j,'#',s)){
        b--;
        s[i][j]='#';
      }
    }
  }
  for(int i=51;i<100;i++){
    for(int j=0;j<100;j++){
      if(a-1>0&&check(i,j,'.',s)){
        s[i][j]='.';
        a--;
      }
    }
  }
  for(int i=0;i<100;i++){
    cout << s[i]<<endl;
  }
}