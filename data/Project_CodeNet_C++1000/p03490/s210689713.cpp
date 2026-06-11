#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define sortall(obj) sort(ALL(obj))
#define revall(obj) reverse(ALL(obj))
#define SortRevAll(obj) revall(sortall(obj))
typedef string str;
typedef long long ll;
const int mod=1e9+7;
const int INF=1e9;
const ll LINF=1e18;
#define V vector
#define P pair
#define F first()
#define S second()
#define PB(a) push_back(a)
#define IN(a) insert(a)
#define ins(a) int a;cin >> a
#define lls(a) ll a;cin >> a
#define in(a) cin >> a
#define sts(a) string (a);cin >> a
#define For(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) For(i,0,n)
#define Forr(i,m,n) for(int i=n-1;i>=m;i--)
#define repr(i,n) Forr(i,0,n)
#define print(a) cout << a << endl
#define Endl cout << endl
#define YES(n) cout << ((n)? "YES" : "NO") << endl
#define Yes(n) cout << ((n)? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE" ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
 
int main()
{
    sts(s);
    ins(x);ins(y);
    V<int>cntx,cnty;
    int sumx=0,sumy=0;
    bool ansx=false,ansy=false;
    int oldf=0,cnt=0;
    s.PB('T');
    rep(i,s.size()){
        if(s.at(i)=='T'){
            int plus=i-oldf-1;
            if(cnt==0){
                cntx.PB(i);
            }else if(cnt%2){
                cnty.PB(plus);
            }else{
                cntx.PB(plus);
            }
            oldf=i;
            cnt++;
        }
        
    }
    bool dpx[8000][16010],dpy[8000][16010];
    rep(i,8000){
        rep(j,16010){
            dpx[i][j]=false;
            dpy[i][j]=false;
        }
    }
    dpx[0][8000]=true;dpy[0][8000]=true;
    For(i,1,cntx.size()+1){
    	rep(j,16001){
    		if(dpx[i-1][j])dpx[i][j+cntx.at(i-1)]=true;
    		if(dpx[i-1][j]&&i!=1)dpx[i][j-cntx.at(i-1)]=true;
    	}
    }
    
    For(i,1,cnty.size()+1){
    	rep(j,16001){
    		if(dpy[i-1][j])dpy[i][j+cnty.at(i-1)]=true;
    		if(dpy[i-1][j])dpy[i][j-cnty.at(i-1)]=true;
    	}
    }
    Yes(dpx[cntx.size()][x+8000]&&dpy[cnty.size()][y+8000]);
    return 0;
}
