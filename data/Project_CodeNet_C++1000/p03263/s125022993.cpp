#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int h,w; cin >> h >> w;
    int s[h][w];
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }
    vector<pair<P,P>> v;
    int cnt=0;
    rep(i,h){
        rep(j,w){
            if(i%2==0){
                if(s[i][j]%2==1){
                    s[i][j]--;
                    if(j!=w-1){
                        s[i][j+1]++; cnt++;
                        P p={i,j},q={i,j+1};
                        v.pb({p,q});
                    }
                    else if(i!=h-1){
                        s[i+1][w-1]++; cnt++;
                        P p={i,j},q={i+1,w-1};
                        v.pb({p,q});
                    }
                    else s[i][j]++;
                }
            }else{
                if(s[i][w-1-j]%2==1){
                    s[i][w-1-j]--;
                    if(w-1-j!=0){
                        s[i][w-1-j-1]++; cnt++;
                        P p={i,w-1-j},q={i,w-1-j-1};
                        v.pb({p,q});
                    }
                    else if(i!=h-1){
                        s[i+1][0]++; cnt++;
                        P p={i,w-1-j},q={i+1,0};
                        v.pb({p,q});
                    }
                    else s[i][w-1-j]++;
                }
            }
        }
    }
    cout << cnt << endl;
    rep(i,v.size()){
        cout << v[i].fi.fi+1 << " "  << v[i].fi.se+1 << " " << v[i].se.fi+1 << " " << v[i].se.se+1 << endl;
    }

}
