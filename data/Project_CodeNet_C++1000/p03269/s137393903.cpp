#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
struct edge{
    int to,cost;
};
V<edge>graph[20];
int main(){
  int n;
  cin>>n;
  n--;
  for(int i=0;i<19;i++){
      graph[i].emplace_back(edge{i+1,0});
  }
  int ind=-1;
  if(~n&(1<<20)){
  for(int i=19;i>=0;i--){
      if(n&(1<<i)){
          ind=i;
          break;
      }
  }
  if(ind==-1){
      int sum=0;
  for(int i=0;i<20;i++)sum+=(int)graph[i].size();
  cout<<20<<" "<<sum<<"\n";
  for(int i=0;i<20;i++){
      for(int j=0;j<graph[i].size();j++){
          cout<<i+1<<" "<<graph[i][j].to+1<<" "<<graph[i][j].cost<<"\n";
      }
  }
  return 0;
  }
  for(int i=18;i>=0;i--){
      if(18-i!=ind)graph[i].emplace_back(edge{i+1,(1<<(18-i))});
      else break;
  }
  graph[0].emplace_back(edge{19,(1<<ind)});
  int x=(1<<ind);
  for(int i=ind-1;i>=0;i--){
      if(n&(1<<i)){
          graph[0].emplace_back(edge{19-i,x+1});
          x+=(1<<i);
      }
  }
  }else{
      graph[0].emplace_back(edge{19,(1<<20)});
      graph[0].emplace_back(edge{19,(1<<19)});
  int x=(1<<20);
  for(int i=18;i>=0;i--){
      if(n&(1<<i)){
          graph[0].emplace_back(edge{19-i,x+1});
          x+=(1<<i);
      }
  }
  x=(1<<19);
  for(int i=18;i>=0;i--){
      if(n&(1<<i)){
          graph[0].emplace_back(edge{19-i,x+1});
          x+=(1<<i);
      }
  }
  if(n&(1<<19)){
      x=(1<<20)+(1<<19);
      for(int i=18;i>=0;i--){
      if(n&(1<<i)){
          graph[0].emplace_back(edge{19-i,x+1});
          x+=(1<<i);
      }
  }
  }
  }
  int sum=0;
  for(int i=0;i<20;i++)sum+=(int)graph[i].size();
  cout<<20<<" "<<sum<<"\n";
  for(int i=0;i<20;i++){
      for(int j=0;j<graph[i].size();j++){
          cout<<i+1<<" "<<graph[i][j].to+1<<" "<<graph[i][j].cost<<"\n";
      }
  }
}