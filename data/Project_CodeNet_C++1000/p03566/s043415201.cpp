#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=1010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};

struct train{
  double v,t;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  vector<int>t(n+10);
  vector<int>v(n+10);
  for(int i=0;i<n;i++)cin>>t[i];
  for(int i=0;i<n;i++)cin>>v[i];

  double ans = 0,speed=0;
  for(int i=0;i<n;i++){
    for(double j=0;j<t[i];j+=0.5){
      bool flag=true,flag2=true;
      double time = t[i]-j-0.5;
      for(int k=i+1;k<n;k++){
	time += t[k];
	if(speed+0.5-time > v[k+1])flag=false;
	if(speed-v[k+1] > time) flag2=false;
      }
      if(speed+0.5 <= v[i] && flag &&(speed+0.5-(t[i]-j-0.5))<=v[i+1]){
	ans += speed*0.5;
	ans += 0.125;
	speed += 0.5;
      }else if(speed - v[i+1] <= t[i]-j-0.5 &&flag2){
	ans += speed*0.5;
      }else{
	speed -= 0.5;
	ans += speed*0.5;
	ans += 0.125;
      }
    }
  }
  printf("%.10lf\n",ans);
  return 0;
}
