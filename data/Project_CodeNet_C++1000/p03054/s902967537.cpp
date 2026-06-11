#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

void solve(){
    int h,w,n;
    cin>>h>>w>>n;
    int sr,sc;
    cin>>sr>>sc;
    string s,t;
    cin>>s>>t;
    int du=sr,dd=h-sr+1,dl=sc,dr=w-sc+1;
    rep(i,n){
        int cnt=0;
        if(s[i]=='U'){
            while(i<n){
                if(s[i]=='U')++cnt;
                if(cnt==du){
                    cout<<"NO\n";
                    return;
                }
                if(t[i]=='D')--cnt;
                ++i;
            }
        }
        if(t[i]=='D')du=min(du+1,h);
    }

    rep(i,n){
        int cnt=0;
        if(s[i]=='D'){
            while(i<n){
                if(s[i]=='D')++cnt;
                if(cnt==dd){
                    cout<<"NO\n";
                    return;
                }
                if(t[i]=='U')--cnt;
                ++i;
            }
        }
        if(t[i]=='U')dd=min(dd+1,h);
    }

    rep(i,n){
        int cnt=0;
        if(s[i]=='L'){
            while(i<n){
                if(s[i]=='L')++cnt;
                if(cnt==dl){
                    cout<<"NO\n";
                    return;
                }
                if(t[i]=='R')--cnt;
                ++i;
            }
        }
        if(t[i]=='R')dl=min(dl+1,w);
    }

    rep(i,n){
        int cnt=0;
        if(s[i]=='R'){
            while(i<n){
                if(s[i]=='R')++cnt;
                if(cnt==dr){
                    cout<<"NO\n";
                    return;
                }
                if(t[i]=='L')--cnt;
                ++i;
            }
        }
        if(t[i]=='L')dr=min(dr+1,w);
    }

    cout<<"YES\n";
}
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
