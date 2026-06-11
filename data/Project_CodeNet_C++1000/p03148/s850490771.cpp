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
void chmax(ll &a,ll b){	if(a<b) a = b ;}
//void chmin(ll &a,ll b){ if(a>b) a = b ;}

int main(){
    ll n,k ;
    cin >> n >> k ;
    vector<pll> a(n) ;
    for(int i=0;i<n;i++) cin >> a[i].second >> a[i].first ;
    sort(all(a)) ;
    reverse(all(a)) ;
    vll cnt(n+1,0) ;
    ll pos1,pos2 ;
    ll sum = 0 ;
    ll add = 0 ;
    for(int i=0;i<k;i++){
        sum += a[i].first ;
        if(cnt[a[i].second]==0) add++ ;
        cnt[a[i].second]++ ;
    }
    pos1 = k-1 ;
    pos2 = k ;
    ll ans = sum+add*add ;
    while(1){
        while(0<=pos1&&cnt[a[pos1].second]<=1) pos1-- ;
        if(pos1==-1) break ;
        while(pos2<n&&cnt[a[pos2].second]>=1) pos2++ ;
        if(pos2==n) break ;
        sum -= a[pos1].first-a[pos2].first ;
        add++ ;
        cnt[a[pos1].second]-- ; pos1-- ;
        cnt[a[pos2].second]++ ; pos2++ ;
        chmax(ans,sum+add*add) ;
    }
    cout << ans << endl ;
}