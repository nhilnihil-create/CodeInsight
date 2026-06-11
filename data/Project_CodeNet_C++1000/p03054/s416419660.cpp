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
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int h,w,n; cin >> h >> w >> n;
    int sr,sc; cin >> sr >> sc;
    string s,t; cin >> s >> t;
    
    int u=0,d=0,l=0,r=0;
    int ue=0,de=0,le=0,re=0;
    
    rep(i,n){
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
        
        if((u-de)>=sr||(d-ue)>=(h-sr+1)||(l-re)>=sc||(r-le)>=(w-sc+1)){
            cout << "NO" << endl;
            return 0;
        }
        
        if(t[i]=='L'){
            le++;
            chmin(le,sc-1+r);
        }
        if(t[i]=='R'){
            re++;
            chmin(re,w-sc+l);
        }
        if(t[i]=='U'){
            ue++;
            chmin(ue,sr-1+d);
        }
        if(t[i]=='D'){
            de++;
            chmin(de,h-sr+u);
        }
    }
    cout << "YES" << endl;
}
