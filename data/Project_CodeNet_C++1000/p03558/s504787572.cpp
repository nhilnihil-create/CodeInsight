#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) ((a+b-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<string> Vs;

template<class T> bool chmax(T &a,T &b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T &b){if(a>b){a=b;return true;}return false;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void start(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);}

signed main(){start();
    int n;
    cin>>n;
    vector<vector<Pii>> connect(n);
    REP(i,1,n){
        connect[i].pb(mp((i+1)%n,1));
        connect[i].pb(mp((i*10)%n,0));
    }
    Vi dist(n,INF);
    dist[1]=0;
    
    priority_queue<Tiii,vector<Tiii>,greater<Tiii>> q;
    q.push(make_tuple(0,1,-1));
    while(!q.empty()){
        int nowdist,now,past;
        tie(nowdist,now,past)=q.top();
        q.pop();
        if(nowdist>dist[now]) continue;
        dist[now]=nowdist;
        if(now==0) break;
        REP(i,0,connect[now].size()){
            int next=connect[now][i].first,cost=connect[now][i].second;
            if(next!=past && nowdist+cost<dist[next]){
                q.push(make_tuple(nowdist+cost,next,now));
                dist[next]=nowdist+cost;
            }
        }
    }
    cout<<dist[0]+1<<endl;
    return 0;
}
