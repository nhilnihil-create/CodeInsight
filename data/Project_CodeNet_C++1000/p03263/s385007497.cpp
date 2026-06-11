#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll h,w;
ll ho[1111][1111];
struct co{
  ll y,x,y1,x2;
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>h>>w;
  vector<co>ans;
  for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>ho[i][j];
  for(int i=0;i<h;i++){
    if(i%2 == 0){
      for(int j=0;j<w;j++){
	if(i == h-1 && j == w-1)continue;
	if(j!=w-1){
	  if(ho[i][j]%2){ho[i][j+1]++;ho[i][j]--;ans.pb({i,j,i,j+1});}
	}else{
	  if(ho[i][j]%2){ho[i+1][j]++;ho[i][j]--;ans.pb({i,j,i+1,j});}
	}
      }
    }else{
      for(int j=w-1;j>=0;j--){
	if(i == h-1 && j == 0)continue;
	if(j!=0){
	  if(ho[i][j]%2){ho[i][j-1]++;ho[i][j]--;ans.pb({i,j,i,j-1});}
	}else{
	  if(ho[i][j]%2){ho[i+1][j]++;ho[i][j]--;ans.pb({i,j,i+1,j});}
	}
      
      }
    }
  }
  cout<<ans.size()<<endl;
  for(auto a:ans){
    cout<<a.y+1<<" "<<a.x+1<<" "<<a.y1+1<<" "<<a.x2+1<<endl;
  }/*
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<ho[i][j]<<" ";
    }
    cout<<endl;
    }*/
  return 0;
}