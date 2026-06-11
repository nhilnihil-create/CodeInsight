#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;

int l[605][605];
int n;

bool check(int a,int b){
    rep(i,n){
        rep(j,n){
            //cerr<<l[a+i][b+j]<<' ';
            if(l[a+i][b+j]!=l[a+j][b+i]){
                return 0;
            } 
        }
        //cerr<<endl;
    }
    return 1;
}

int main(){
    cin >> n;
    rep(i,n){
        rep(j,n){
            char s;
            cin >> s;
            int t=s-'a';
            l[i][j]=t;
            l[i+n][j]=t;
            l[i][j+n]=t;
            l[i+n][j+n]=t;
        }
    }
    int ans=0;
    rep(k,n){
        if(check(k,0)==1){
            ans+=n-k;
            //cerr<<k<<' '<<ans<<endl;
        }
    }
    
    rep(k,n){
        if(check(0,k)==1){
            ans+=n-k;
        }
    }
    if(check(0,0)==1)ans-=n;
    
    cout<<ans<<endl;
    return 0;
}