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

const int C_MAX = 26;

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin>>N>>Q;
    string S; cin>>S;
    vector<char> t(Q);
    vi mv(Q);
    rep(i,Q){
        char d; cin>>t[i]>>d;
        mv[i] = (d=='L')?-1:1;
    }
    int l=-1,r=N;
    while(r-l>1){
        int c = (l+r)/2;
        int now = c;
        char nc = S[now];
        bool ng=false;
        rep(i,Q){
            if (nc==t[i]){
                now+=mv[i];
                if (now<0) ng=true;
                if (now<0 || now>=N) break;
                nc = S[now];
            }
        }
        (ng)?l=c:r=c;
    }
    int left = r;
    l=-1,r=N;
    while(r-l>1){
        int c = (l+r)/2;
        int now = c;
        char nc = S[now];
        bool ng=false;
        rep(i,Q){
            if (nc==t[i]){
                now+=mv[i];
                if (now>=N) ng=true;
                if (now<0 || now>=N) break;
                nc = S[now];
            }
        }
        (ng)?r=c:l=c;
    }
    int right = r;
    cout<<right-left<<endl;
    return 0;
}
