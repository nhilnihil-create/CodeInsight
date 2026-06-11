#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vs> ws;
const ll INF=1LL << 60;
const ll MOD=1e9+7;

char chchar(int num){
  char c='5';
  if(num==0)c='0';
  else if(num==1)c='1';
  else if(num==2)c='2';
  else if(num==3)c='3';
  else if(num==4)c='4';
  else if(num==5)c='5';
  else if(num==6)c='6';
  else if(num==7)c='7';
  else c='8';
  return c;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  char s[h+2][w+2];
  rep(i, h+2)rep(j, w+2)s[i][j]=='.';
  rep1(i ,h)rep1(j, w)cin >> s[i][j];

  int cnt;
  char ans[h][w];
  rep1(i, h){
    rep1(j, w){
      cnt=0;
      if(s[i][j]=='#'){
        ans[i][j]='#';
        continue;
      }
      if(s[i+1][j]=='#')cnt++;
      if(s[i+1][j+1]=='#')cnt++;
      if(s[i+1][j-1]=='#')cnt++;
      if(s[i-1][j]=='#')cnt++;
      if(s[i-1][j+1]=='#')cnt++;
      if(s[i-1][j-1]=='#')cnt++;
      if(s[i][j+1]=='#')cnt++;
      if(s[i][j-1]=='#')cnt++;
      char c=chchar(cnt);
      ans[i][j]=c;
    }
  }

  rep1(i, h){
    rep1(j, w){
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}