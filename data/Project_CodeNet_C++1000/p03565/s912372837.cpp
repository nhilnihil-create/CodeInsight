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
    string s,t; cin >> s >> t;
    if(s.size()<t.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    for(int i=s.size()-t.size();i>=0;i--){
        bool ok=1;
        rep(j,t.size()){
            if(s[i+j]!=t[j]&&s[i+j]!='?') ok=0;
        }
        if(ok){
            rep(j,s.size()){
                if(j==i){
                    cout << t;
                    j+=t.size()-1;
                }
                else if(s[j]=='?') cout << "a";
                else cout << s[j];
            }
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
}
