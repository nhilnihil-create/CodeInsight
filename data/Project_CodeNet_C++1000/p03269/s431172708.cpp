#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

struct edge{
  ll a,b,w;
  edge(ll x,ll y,ll z):a(x),b(y),w(z){}
};

ll f(ll x){
  ll res=0,crt=1;
  while(crt*2<=x){
    crt*=2; res++;
  }
  return res;
}

void show(edge e){
  cout<<e.a<<" -> "<<e.b<<" : "<<e.w<<endl;
}

ll L;
vector<edge> es;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>L;
  L--;
  ll b=f(L);
  ll N=b+1;

  if(b==0){
    cout<<2<<" "<<2<<endl;
    cout<<1<<" "<<2<<" "<<0<<endl;
    cout<<1<<" "<<2<<" "<<1<<endl;
    return 0;
  }

  rep(i,b){
    es.push_back(edge(i,i+1,(1<<i)));
    es.push_back(edge(i,i+1,0));
    // show(edge(i,i+1,(1<<i)));
    // show(edge(i,i+1,0));
  }

  ll l=(1<<b);
  // dbg(l);
  // dbg(L);
  while(l<=L){
    // l-L
    ll cnt=(L-l+1);
    ll step=min(f(cnt),b-1);
    // dbg(step);
    es.push_back(edge(step,N-1,l));
    // show(edge(step,N-1,l));
    l+=(1<<step);
  }

  cout<<N<<" "<<es.size()<<endl;
  rep(i,es.size()){
    cout<<es[i].a+1<<" "<<es[i].b+1<<" "<<es[i].w<<endl;
  }

  return 0;
}
