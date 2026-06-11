#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    string s;
    cin >> s;
    ll X,Y;
    cin>>X>>Y;
    ll N=s.size();
    ll si=0;
    while(si<N&&s[si]!='T')si++;
    X-=si;
    
    ll xy=0,d=0;
    vvc<ll> xyl(2,vl(1,0));
    repe(i,si,N){
    	if(s[i]=='T'){
    		if(d)xyl[xy].eb(d);
    		xy=(xy+1)%2;
    		d=0;
    	}else
    		d++;
    }
    if(d)xyl[xy].eb(d);
    
    ll szx=0,szy=0;
    for(auto x:xyl[0])szx+=x;
    for(auto y:xyl[1])szy+=y;
    if(X<-szx||szx<X||Y<-szy||szy<Y){
    	cout<<"No"<<endl;
    	return 0;
    }

    ll xn = xyl[0].size(), yn = xyl[1].size();
    vvc<ll> dpx(xn+1, vl(2*szx+1,false)),dpy(yn+1, vl(2*szy+1,false));
    dpx[0][szx]=dpy[0][szy]=true;
    
    ll dpsz=szx*2+1;
    rep(i,xn){
    	rep(j,dpsz){
            if (j + xyl[0][i] < dpsz) dpx[i + 1][j] |= dpx[i][j + xyl[0][i]];
            if (j - xyl[0][i] > 0) dpx[i + 1][j] |= dpx[i][j - xyl[0][i]];
        }
    }

    dpsz=szy*2+1;
    rep(i,yn){
        rep(j,dpsz){
            if (j + xyl[1][i] < dpsz) dpy[i + 1][j] |= dpy[i][j + xyl[1][i]];
            if (j - xyl[1][i] > 0) dpy[i + 1][j] |= dpy[i][j - xyl[1][i]];
        }
    }

    if (dpx[xn][X + szx] && dpy[yn][Y + szy])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
