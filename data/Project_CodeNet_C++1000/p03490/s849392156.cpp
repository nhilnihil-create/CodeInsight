#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  string s;
  cin>>s;
  int n=s.size();
  int x,y;
  cin>>x>>y;
  int d=0;
  vector<vi> a(2);
  rep(i,n){
    int t=0;
    while(s[i]=='F'&&i<n)t++,i++;
    a[d].push_back(t);
    d=1-d;
  }
  int g=8000;
  int dx[2][2*8000]={},dy[2][2*8000]={};
  dx[0][g]=dy[0][g]=1;
  rep(i,a[0].size())rep(j,2*g)if(dx[i%2][j]){
    dx[(i+1)%2][j+a[0][i]]=1;
    if(i>0)dx[(i+1)%2][j-a[0][i]]=1;
    dx[i%2][j]=0;
  }
  rep(i,a[1].size())rep(j,2*g)if(dy[i%2][j]){
    dy[(i+1)%2][j+a[1][i]]=1;
    dy[(i+1)%2][j-a[1][i]]=1;
    dy[i%2][j]=0;
  }
  if(dx[(int)(a[0].size())%2][x+g] && dy[(int)(a[1].size())%2][y+g])cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
