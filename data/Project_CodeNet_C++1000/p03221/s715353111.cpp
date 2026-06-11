#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int keta(int s){
  int i=0;
  while(s>0){
    s/=10;
    i++;
  }
  return i;
}
void zero(int s){
  int i=6-keta(s);
  rep(e,i){
    cout<<0;
  }
}
int main(){
int n,m;
cin>>n>>m;
pair<int,int> p[m],P[m];

rep(i,m){
  int N,q;
  cin>>N>>q;
  p[i]=make_pair(N,q);
  P[i]=make_pair(N,q);
}
p[m]=make_pair(INF,0);
sort(p,p+m);
vector<map<int,int>> mp(n+1);
int I=0;
rep(i,m){
  I++;
  mp[p[i].first][p[i].second]=I;
  if(p[i].first!=p[i+1].first) I=0;
}

rep(i,m){
  zero(P[i].first);
  cout<<P[i].first;
  zero(mp[P[i].first][P[i].second]);
  cout<<mp[P[i].first][P[i].second];
  cout<<endl;
}

  return 0;
}
