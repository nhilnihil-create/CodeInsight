#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
//void chmax(ll &a,ll b){	if(a<b) a = b ;}
//void chmin(ll &a,ll b){ if(a>b) a = b ;}
void strmax(string &a,string &b){
    if(a.size()<b.size()) a = b ;
    else if(a.size()==b.size()){
        for(int i=(int)a.size()-1;i>=0;i--){
            if(a[i]>b[i]) break ;
            if(a[i]<b[i]){
                a = b ;
                break ;
            }
        }
    } 
}

int main(){
    ll n,m ;
    cin >> n >> m ;
    vll cnt = {0,2,5,5,4,5,6,3,7,6} ;
    for(int i=0;i<m;i++){
        ll a ; cin >> a ;
        cnt[a] -= INF ;
    }
    for(int i=0;i<10;i++) cnt[i] += INF ;
    vector<string> dp(n+1,"") ;
    for(int i=1;i<=n;i++){
        string s = "" ;
        for(int j=1;j<10;j++){
            if(cnt[j]>i) continue ;
            if(i-cnt[j]!=0&&dp[i-cnt[j]]=="") continue ;
            s = dp[i-cnt[j]]+(char)(j+'0') ;
            strmax(dp[i],s) ;
        }
    }
    string ans = dp[n] ;
    reverse(all(ans)) ;
    cout << ans << endl ;
    // for(int i=1;i<=n;i++){
    //     cout << i << " : " << dp[i] << endl ;
    // }
}