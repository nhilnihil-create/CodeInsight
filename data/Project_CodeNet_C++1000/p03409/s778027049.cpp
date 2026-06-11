#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

struct Event {
    int id,x,y;
    Event(int id, int x, int y):id(id),x(x),y(y){}
    bool operator<(const Event &e){return x<e.x;}
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<Event> event;
    rep(i,n){
        int x,y; cin>>x>>y;
        event.pb(Event(0,x,y));
    }
    rep(i,n){
        int x,y; cin>>x>>y;
        event.pb(Event(1,x,y));
    }
    sort(all(event));
    int ans=0;
    set<int> s; s.ins(-1);
    for(auto e:event){
        if (e.id==0){
            s.ins(e.y);
        }else{
            auto itr = s.lower_bound(e.y); itr--;
            if (*itr==-1) continue;
            ans++;
            s.erase(itr);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
