#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int root(int arr[],int i){
    while(arr[i]!=i){
         arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}
void Union(int arr[],int Size[],int a,int b){
int rootA=root(arr,a);
int rootB=root(arr,b);
if(Size[rootA]<Size[rootB]){
    arr[rootA]=arr[rootB];
    Size[rootB]+=Size[rootA];
}else{
arr[rootB]=arr[rootA];
Size[rootA]+=Size[rootB];
}
}
bool findRoot(int a,int b,int arr[]){
 if(root(arr,a)==root(arr,b))return true;
 else return false;
}

bool nCyc=false;
/*void dijkstra(int v,long long dis[]){
dis[v]=0;
multiset<pair<int,int> >s;
s.insert({0,v});
while(!s.empty()){
    pair<int,int>p= *s.begin();
    s.erase(s.begin());
    int x=p.second;
  if(vis[x])continue;
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++){
        int e=adj[x][i].first,w=adj[x][i].second;
      //  cout<<dis[e]<<" "<<dis[x]+w<<endl;
        if(dis[e]>dis[x]+w){
            dis[e]=dis[x]+w;
            s.insert(make_pair(dis[e],e));
        }
    }
}
}*/
/*void bfs(int s){
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++){
            if(!vis[adj[v][i]]){
                 q.push(adj[v][i]);
                 vis[adj[v][i]]=1;
            }
        }
    }
}*/


/*bool isVal(int i,int j){
      if(i<0 || j<0 || j>=m || i>=n)return false;
      return true;
}*/
/*void dfs(int i,int j) {

    if(!isVal(i,j) || vis[i][j] || arr[i][j]=='#')return;
      vis[i][j]=1;
	  if(arr[i][j]=='G'){
	  check++;
	  }
	  if(arr[i][j]=='B'){
        b=1;
        return;
	  }
	for(int k=0;k<4;k++){
     int pos1=i+dx[k],pos2=j+dy[k];
   //  cout<<pos1<<" "<<pos2<<endl;
     if( isVal(pos1,pos2) && (arr[pos1][pos2]=='#'))continue;
               dfs(pos1,pos2);
	}
}
void dfs2(int i,int j){
 if(isVal(i,j)==false || arr[i][j]!='.')return;
  arr[i][j]='#';
}*/
/*
double prim(int x){
    priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >q;
    double min_cost=0.0;
    pair<double,int>p;
     q.push(make_pair(0.0,x));
     while(!q.empty()){
      p=q.top();
      q.pop();
      x=p.second;
      if(vis[x])continue;
      min_cost+=p.first;
      vis[x]=1;
      for(int i=0;i<adj[x].size();i++){
         int y=adj[x][i].second;
         if(!vis[y]){
            q.push(adj[x][i]);
        }
      }
     }
   return min_cost;
}*/


bool check(int i,int mask){
    return(mask&(1<<i))!=0;
}

int setBit(int i, int mask){
    return (mask | (1<<i));
}

bool isPrime(long long x){
    if(x==2)return true;
    if(x%2==0 || x<2)return false;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0)return false;
    return true;
}
queue<pair<int,int> >q;
vector<pair<int,int> >nodes;
int dist[25][25],cost[25][25];
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};
char adj[25][25];
void bfs(int i,int j){
  pair<int,int>p;
 memset(dist,-1,sizeof dist);
  dist[i][j]=0;
  q.push(make_pair(i,j));
  while(!q.empty()){
   p=q.front();
   q.pop();
    for(int i=0;i<8;i++){
      int pos1=p.first+dx[i],pos2=p.second+dy[i];
        if( dist[pos1][pos2]==-1){
          dist[pos1][pos2]=dist[p.first][p.second]+1;
          q.push(make_pair(pos1,pos2));
        }
    }
  }
}
string s,t;
int dp[3005][3005];
int solve (int i,int j){
  if(i>=s.length() || j>=t.length() )return 0;
if(dp[i][j]!=-1)return dp[i][j];

if(s[i]==t[j])return dp[i][j]=1+solve(i+1,j+1);
else if(s[i]!=t[j]){
    return dp[i][j]=max(solve(i+1,j),solve(i,j+1));
}
}
string ans="";
void trace(int i,int j){
 if(i>=s.length() || j>=t.length() )return;
 if(s[i]==t[j]){
    ans=ans+s[i];
    trace(i+1,j+1);
 }else{
  if(dp[i][j]==dp[i+1][j])trace(i+1,j);
  else trace(i,j+1);
 }
}
int vis[100005];
int main()
{
//freopen("diamond.in", "r", stdin);
//freopen("diamond.out","w", stdout);
cin>>s>>t;
memset(dp,-1,sizeof dp);
int a=solve(0,0);
trace(0,0);
cout<<ans<<endl;
return 0;
}
