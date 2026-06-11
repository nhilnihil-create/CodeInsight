#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

typedef long long ll;

using namespace std;

const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;
const ll LINF = 1e18;
long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
      cin>>n>>m>>s;
      vector<ll> g[ohara];
      map<ll,ll> a;
      map<ll,ll> b;
      queue<ll> que;
      map<ll,ll> out;
      rep(i,m){
        cin>>c>>d;
        c--;d--;
        g[c].push_back(d);
        g[d].push_back(c);
      }
      rep(i,n){
        rep(j,Size(g[i])){
          pos=g[i][j];
          if(s[pos]=='A')a[i]++;
          else b[i]++;
      }
      }
      rep(i,n){
        if(a[i]==0||b[i]==0)que.push(i),out[i]=1;
      }
      while(!que.empty()){
        ll v=que.front();que.pop();
        rep(i,Size(g[v])){
          pos=g[v][i];
          if(out[pos]==1)continue;
          if(s[v]=='A')a[pos]--;
          else b[pos]--;
          if(a[pos]==0||b[pos]==0){
            que.push(pos);
            out[pos]=1;
          }
        }
      }
      rep(i,n)if(out[i])cnt++;
      if(cnt==n)Cout("No");
      else Cout("Yes");
    
       
return 0;
}
