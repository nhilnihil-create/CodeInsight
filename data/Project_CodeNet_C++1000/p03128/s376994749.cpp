#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define bFor(i,a,b) for(i=a;i>=b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}while(0)
const ll mod=1000000007;
const ll inf=1LL<<60;

long mmid(long a,long b,long c){return a<b?(b<c?b:max(a,c)):(b>c?b:min(a,c));}

ll modinv(ll a) {
  ll b=mod,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+mod)%mod;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}

ll modncr(ll n,ll r){
  ll i,plus=1;
  rep(i,r){
    plus=(plus*(n-i))%mod;
    plus=moddevide(plus,i+1);
  }
  return plus;
}

ll euclidean_gcd(ll a, ll b) {
  if(a<b) return euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)){a=b;b=r;}
  return b;
}

void printmap(vector<ll>& a,ll H,ll W){
  ll i,j;
  For(i,0,H+2){
    For(j,0,W+2){cout<<a[i*(W+2)+j];}
    cout<<endl;
  }
}
void inputmap(vector<ll>& a,ll H,ll W){
  ll i,j;
  string ss;
  For(i,1,H+1){
    cin>>ss;
    For(j,1,W+1){
      if(ss[j-1]=='#'){
        a[i*(W+2)+j]=1;
      }else{
        a[i*(W+2)+j]=0;
      }
    }
  }
}

int main(){
  ll i=0,j,k,N,M,x,y;
  ll priority[9]={1,7,4,5,3,2,9,6,8},cost[10]={0,2,5,5,4,5,6,3,7,6};
  cin>>N>>M;
  vector<ll> list(10,0),v;
  rep(j,M){
    cin>>x;
    list[x]++;
  }
  while(list[priority[i]]==0){
    i++;
  }
  x=N/cost[priority[i]];
  y=N-x*cost[priority[i]];
  if(y==0){
    rep(j,x){
      cout<<priority[i];
    }
    cout<<endl;
    return 0;
  }
  rep(j,i){
    if(list[priority[j]]&&cost[priority[j]]<=y){
      break;
    }
  }
  if(j!=i){
    if(cost[priority[j]]==y){
      if(priority[i]>priority[j]){
        rep(k,x){
          cout<<priority[i];
        }
        cout<<priority[j]<<endl;
      }else{
        cout<<priority[j];
        rep(k,x){
          cout<<priority[i];
        }
        cout<<endl;
      }
      return 0;
    }
    x+=1;
  }

  priority_queue<ll> que;
  while(x>6){
    que.push(priority[i]);
    N-=cost[priority[i]];
    x--;
  }
  rep(j,10){
    if(list[j])v.push_back(j);
  }
while(x){
  M=pow(v.size(),x);
  brep(i,M){
    j=i;
    vec tr(v.size(),0);
    rep(k,x){
      tr[j%v.size()]++;
      j/=v.size();
    }
    ll cnt=0;
    rep(k,(ll)v.size()){
      cnt+=tr[k]*cost[v[k]];
    }
    j=i;
    if(cnt==N){
      while(x--){
        que.push(v[j%v.size()]);
        j/=v.size();
      }
      x=0;
      break;
    }
  }
  if(x)x--;
}
  while(!que.empty()){
    cout<<que.top();que.pop();
  }
  cout<<endl;
  return 0;
}