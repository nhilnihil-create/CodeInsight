#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b,c;cin >> n >> a >> b >> c;
    vector<int> l(n);
    REP(i,n){
        cin >> l[i];
    }
    int ans=inf;
    REP(i,1<<(n*2)){
        vector<int> d(n);
        int num=i,cnt=0;
        while(num){
            d[cnt]=num%4;
            num/=4;
            cnt++;
        }
        vector<int> p(3),q(3);
        REP(j,n){
            if(d[j]==1){
                p[0]+=l[j];
                q[0]++;
            }
            if(d[j]==2){
                p[1]+=l[j];
                q[1]++;
            }
            if(d[j]==3){
                p[2]+=l[j];
                q[2]++;
            }
        }
        if(q[0]==0||q[1]==0||q[2]==0){
            continue;
        }
        int res=abs(a-p[0])+abs(b-p[1])+abs(c-p[2])+10*(q[0]+q[1]+q[2]-3);
        chmin(ans,res);
    }
    cout << ans << endl;
}