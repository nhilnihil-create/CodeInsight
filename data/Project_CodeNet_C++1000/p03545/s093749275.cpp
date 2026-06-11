#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


string s;

void bfs(string w,int i,int sum){
  if(i==4&&sum==7){
    cout << w+"=7"<<endl;
    exit(0);
  }
  if(i==4) return;
  bfs(w+"+"+s[i],i+1,sum+(int)(s[i]-'0'));
  bfs(w+"-"+s[i],i+1,sum-(int)(s[i]-'0'));
}
int main() {
  string w="";
  cin>>s;
  w+=s[0];
  bfs(w,1,(int)(s[0]-'0'));
}